/******************************************    *******************************

      > File Name: const.cpp

      > Author: Ywl

      > Descripsion:

      > Created Time:     Mon 28 May 2018 12:11:32 AM PDT

      > Modify Time: 

 *********************************    ***************************************/

#include <iostream>
#include <string>
#include <stdio.h>

/* const static 初始化列表 */

class pri{
private:
    const std::string languge = "cplusplus";
    const std::string plat;
    //static pri var;       //static 可以定义这个类的成员
    //static int num = 0;     /* static 不允许这里初始化 */
    static int num;     /* static 修饰的不能用初始化列表 */
    static const int unini = 9; /* 这个可以初始化 */
    static const int unini2; /* 这个可以初始化 */
    /* static的生命周期是整个程序结束，因此在创建实例的调用构造函数去初始化是不合理的,
     * 并且这些变量是所有类和实例共享的, 不占类的内存空间
     * 只有static修饰，不占类的内存空间，共享
     * static const修饰，占内存空间，共享，但是不可变
     *
     * */
    int common;
    int &addr;  /* 引用类型必须用初始化列表,因为引用类型没法赋值 */
public:
    pri(int &addr_) : addr(addr_), languge("cplusplus"), plat("github"), common(19){}  /* 对于const修饰的必须用初始化列表 */
    ~pri(){}

    void print_plat(void) const{    /* 访问const修饰的变量必须的函数用const */
        std::cout << plat << std::endl;
    }
    static void print_languge(pri arg)
    {
        std::cout << arg.languge << std::endl;  /* static 方法是共有的，所以没有this指针, 与普通函数没啥区别 */
        std::cout << num << std::endl;  /* 整个类范围的，所以可以访问 */
    }
    /*
     * 静态成员函数的地址可用普通函数指针储存，而普通成员函数地址需要用类成员函数指针来储存
     * class base{   
     *     static int func1();   
     *     int func2();   
     * };   
     *           
     * int (*pf1)()=&base::func1;//普通的函数指针   
     * int (base::*pf2)()=&base::func2;//成员函数指针
     *
     * 静态成员函数不可以同时声明为 virtual、const、volatile函数
     * */
};

//const int pri::unini = 7; consta只能初始化一次，这里重复初始化了
const int pri::unini2 = 7;
int pri::num = 8;

int main(){
    char num = 9;
    char num1 = 9;
    char num2 = 9;
    char num3 = 9;
    char num4 = 9;
    const char *a = &num;
    char const *b = &num1;
    char * const c = &num2;
    const char * const d = &num4;

    /* const 
     * 理解比较简单，在谁前面就修饰谁
     * 在*前面就修饰指向的变量，
     * 比如 *a 代表的是一个变量的值，a代表的是一个地址
     * const *a 表示这个变量(*a就是a指向的那个变量)不能改变，const a 表示这个变量(a是个指针变量)不能表改变,即不能指向别的地址了
     * */
    //c = &num4;
    printf("%ld\n", sizeof(std::string));
    printf("%ld\n", sizeof(class pri));

    int addr = 90;

    pri var1(addr);
    pri::print_languge(var1);
    var1.print_languge(var1);

    return 0;
}
