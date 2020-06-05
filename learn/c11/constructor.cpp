#include <cstdio>
#include <iostream>

using namespace std;

class Base {
public:
  int val1;
  int val2;
  Base() {
    val1 = 1;
  }

  Base(int val) : Base() {  // 这里可以直接调用内部的其他构造函数，做一些基本的初始化
    val2 = val;
  }

  void f(double i) {
    printf("base %f\n", i);
  }
};

class SubClass : public Base {
  public:
    using Base::Base; // 继承构造，这样会继承基类的所有构造函数，会调用相应版本的构造函数

    using Base::f;  // 那么此时不会覆盖基类函数
  void f(int i) {
    printf("base %d\n", i);
  }
};

int main(void)
{
  Base a(2);

  printf("val1 : %d, val2 : %d\n", a.val1, a.val2);

  SubClass b(3);
  b.f(9);
  b.f(9.9);

  printf("val1 : %d, val2 : %d\n", b.val1, b.val2);

  return 0;
}
