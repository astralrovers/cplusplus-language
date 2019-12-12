#include <iostream>

int main(void)
{
  int a = 10;
  int & b = a;
  int & c = b;

  std::cout << "c : " << c << '\n';

  c = 90;

  std::cout << "a : " << a << '\n';

  return 0;
}
