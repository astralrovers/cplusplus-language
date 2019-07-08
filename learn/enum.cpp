#include <iostream>
using namespace std;

int main(void)
{
  enum Aenum { red = 1, blue = 2};

  // 注意下面两行代码在c语言中是不允许的
  Aenum enum1;
  enum1 = Aenum(3);

  cout << "enum1 = " << enum1 << '\n';

  return 0;
}

