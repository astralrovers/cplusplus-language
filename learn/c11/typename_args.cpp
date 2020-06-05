#include <iostream>

using namespace std;

// 这是一个printf类似接口
template <typename... Args>
void print(const std::string &str, Args... args);


template <typename T0, typename... T>
void printfa(T0 t0, T... t) // 这里的...相当于打包所有参数
{
  cout << t0 << '\n';
  // 这里可以使用sizeof...计算变参长度
  if constexpr (sizeof...(t) > 0)
  {
    // 使用这种方式将变参拆开传递给一个变参模板函数
    printfa(t...);
  }
}

int main(void)
{
  printfa("hello", "world", 2019);
  return 0;
}
