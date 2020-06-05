#include <iostream>

using namespace std;


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


int main(void)
{
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
      // 不允许当作左值被修改
      return text[item];
    }
    int & operator[](const int item) {
      // 可以当作左值被修改
      return text[item];
    }
  };

  const Test one;
  Test one1;

  // one[0] = 3; // 类似只读
  one1[0] = 4; // 可读可写
  cout << "0 : " << one1[0] << endl;



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


  return 0;
}
