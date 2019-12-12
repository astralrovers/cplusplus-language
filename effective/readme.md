# `effective c++`

[TOC]

## 1. 尽量使用`const`、`enum`、`inline`来替换`define`

### `define`缺陷

- 用于定义字符串或者数字；
  - 一个是`define`定义的标号，无法在调试时体现出来，因为它在编译时就被替换掉了；
  - 二是占内存，由于是替换，所以每一次使用时都会分配一个内存；
  - 三是封装性，`define`定义的无法专属于某一个`class`，它是全局的，没有`private #define`的概念。
- 用于运算或者代码段
  - 一是括号问题，可能导致替换后，由于运算符优先级导致的预期错误；
  - 二是可读性

### `const`、`enum`、`inline`优势

- `const`、`enum`正常使用情况下是不允许改变的，而且内存只有一份；
- `inline`可读性更好；
- 都能够专属于某个类。

### 例子

**const**

```c++
const int MAX_LEN = 5;

// 这个是不允许改变的，*LAYER_MAX_LEN = 9的操作是不允许的
// 因为*LAYER_MAX_LEN是const修饰，不允许改变
const int * CONST_VAR = &MAX_LEN;

// 像这个的话CONST_PTR = ...;操作是不允许的，因为CONST_PTR被const修饰
// *CONST_PTR = ...;却是可以的
int I_MAX_LEN = 8;
int * const CONST_PTR = &I_MAX_LEN;

// 要区分前两种其实很简单，const在谁前面就修饰谁，第一个*LAYER_MAX_LEN,第二个CONST_PTR

// 这样的话都无法修改了
const int * const CONST_CONST = &MAX_LEN;

const char * COM_NAME = "hik";

// 类里面的使用
class GamePlayerOne {
    static const int MAX_NUM = 5;  // 注意虽然这里可以初始化，但是因为有static修饰，而且只能对int char bool类型进行初始化，最好是只声明，在外面显示定义初始值
    int scores[MAX_NUM];   // 这里要使用常量
};

// 显示初始化
class GamePlayerTwo {
    static const int MAX_NUM;
};

const int GamePlayerTwo::MAX_NUM = 5;

// 使用参数列表也可以
class GamePlayerThree {
    const int MAX_NUM;
    GamePlayerThree(const int MAX_NUM):MAX_NUM(MAX_NUM) {}
};

// 用于修饰class函数
class Test {
    private:
    int text[20];
    public:
    Test() {
        int i = 0;
        for (i = 0; i < 20; i++) {
            text[i] = i;
        }
    }
    // 这里使用的const 不同算是重载，前后都要加const才行
    const int & operator[](const int item) const {
        // 不允许当作左值被修改，它的返回的是一个const
        return text[item];
    }
    int & operator[](const int item) {
        // 可以当作左值被修改
        return text[item];
    }
};

const Test one;  // 这样定义的会调用const版本的
Test one1;

// one[0] = 3; // 类似只读
one1[0] = 4; // 可读可写
cout << "0 : " << one1[0] << endl;

// 其实更有用的是用于参数
void xxx(const Test & one); // 这样的话就会自动调用const版本的，也就保证的，one不会被更改
```

**可修改的const成员函数**

```c++
  // 如果说使用const修饰的成员函数，我们有想要更改的其他成员属性，可通过以下方法
  class ChangeConst {
    private:
        mutable int num;  // 用这个修饰的变量，const修饰的成员函数可以修改它的值
    public:
        void add(void) const {
            num++;
        }
        void print_num(void)
        {
            std::cout << num << std::endl;
        }
  };

  ChangeConst __mutconst;
  __mutconst.add();
  __mutconst.add();
  __mutconst.print_num();


  // 有时候如前面的[]存在两个版本，但是如果说里面有很多的操作，那写两份会代码冗余，是时候合成一份了
  class TestRedundancy {
  private:
    int text[20];
  public:
    TestRedundancy() {
      int i = 0;
      for (i = 0; i < 20; i++) {
        text[i] = i;
      }
    }
    // 这里使用的const 不同算是重载，前后都要加const才行
    const int & operator[](const int item) const {
      // 不允许当作左值被修改
      // 这里做一些修改mutable1修饰的数据
      return text[item];
    }
    int & operator[](const int item) {
      // 可以当作左值被修改
      // const_cast 将const数据安全修改为非const数据,static_cast是进行安全强制类型转换
      // 调用const版本的函数，只是将返回值修改掉
      return const_cast<int &>(static_cast<const TestRedundancy &>(*this)[item]);
    }
  };

  const TestRedundancy oneredundancy;
  Test one1redundancy;

  one1redundancy[0] = 7; // 可读可写
  cout << "0 : " << one1redundancy[0] << endl;
```



**enum**

```c++
enum class new_def {
    MAX_LEN___ = 90
};

enum { MAX_LEN___ = 6 };

class Test {
    public:
        enum { MAX_LEN = 5 };

        // 直接使用MAX_LEN
        int scores[MAX_LEN];

};

int main(void)
{
    // 这个是无法使用的
    // std::cout << MAX_LEN << std::endl;
    std::cout << Test::MAX_LEN << std::endl;
    // 由于cout不支持输出enum class类型，所以要强制转换
    std::cout << static_cast<int>(new_def::MAX_LEN___) << std::endl;
    std::cout << MAX_LEN___ << std::endl;
    return 0;
}
```

**inline**

```c++
#include <iostream>

static inline void print(void)
{
    std::cout << "ok" << std::endl;
}

int main(void)
{
    print();
    return 0;
}
```

成员函数默认是`inline`，不过`inline`函数大多用于简单，处理快速，调用频繁的代码段，如果过于复杂编译器并不能保证它被编译为`inline`。

## 2. 变量被使用确保已经被初始化

> 首先说明几个问题：声明、初始化、赋值。
>
> - 声明即：`int a;`
> - 初始化：`int a = 10;`
> - 赋值：`int a; a = 10;`
>
> 其实这里的初始化即是在生命时进行赋值，如果只声明不赋值，它将时一个随机值，在你使用时会与预期结果不一致。

### 类成员属性的初始化

我们知道，一般而言对象的成员属性初始化时在构造函数内：

```c++
class Init1 {
    private:
        int a;
        const int b;

    public:
        Init1(int a, const int b) : b(b) {  // 对于b而言使用的是初始化列表，这种方式是十分搞笑的，它在构造函数执行之前，而且const必须用这样的方式
            a = a;  // 对于b而言，其实是赋值
        }
};
```

要注意的是采用初始化列表的方式是最佳的，效率最高，另外初始化列表的初始化顺序是一定的，和你书写的顺序无关，规则是：先声明先初始化，父类成员属性先初始化。

## 3. 默认函数

`c++`类本身会提供高一些默认的函数，如：构造函数，拷贝构造函数、拷贝复制函数、析构函数。

```c++
class Empty{};

// 其实等于下边
class Empty{
    Empty() { ... }    // Empty e1;
    ~Empty() { ... }
    Empty(const Empty &) { ... }  // Empty e2(e1);
    
    Empty &operation=(const Empty &) { ... }  // e2 = e1;
};
```

如果你声明了(之后必须得实现定义)这些函数，那么原本的默认函数是不会被调用了。

**最好是自己要实现这些函数**，原因在于比如拷贝函数，他们只是单纯地把一个实例的每一个字节拷贝到另一个实例，对于普通变量没有什么问题，但是对于引用类型：

```c++
class TestRef {
private:
    int *num;
    string &name;
    const int age;
public:
    TestRef(int *num, string &name, const int age) : ....
};

int num = 90;
string name("c++");
const int age = 18;

TestRef ref1(&num, name, age);

TestRef ref2(...);

ref2 = ref1;
// 这将会出现错误
// 1. num是指针，那么ref2的num等于ref1的num，当ref1的num变化时，ref的num将变化
// 2. name是引用，引用是不允许指向不同对象的
// 3. age是const，不允许被改变
```

