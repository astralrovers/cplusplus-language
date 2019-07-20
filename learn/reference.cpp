#include <iostream>

using namespace std;

// 这里的&也表示引用，函数内部改变它的值，其实就是改变参数的值，外面也会改变。区别于指针，比指针安全
void set_a_var(int &a)
{
  a = 90;

  return;
}

int main(void)
{
  int a = 10;
  int &b = a; // 定义变量时在前面添加&表示这个变量是一个引用，必须初始化，而且无法成为零一个变量的引用，也就是a的另一个名字，他们是同一个变量

  cout << b << '\n';

  b = 20;

  cout << a << '\n';

  set_a_var(a);
  cout << a << '\n';

  return 0;
}
