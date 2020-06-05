#include <iostream>

// 使用字面量作为模板参数
template <typename T, int size>
void print(T age)
{
  std::cout << "age : " << age << '\n';
  std::cout << "size : " << size << '\n';
}

int main(void)
{
  print<int, 18>(18);
  return 0;
}
