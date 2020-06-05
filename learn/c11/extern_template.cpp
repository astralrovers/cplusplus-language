#include <iostream>

template <typename T>
void method(T arg)
{
  std::cout << arg << '\n';
}

// 引用外部模板，这里实例化在下方
extern template void method<int>(int arg);

// 实例化
template void method<int>(int arg);

int main(void)
{
  method<int>(6);
  return 0;
}
