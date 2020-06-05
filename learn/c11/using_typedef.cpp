#include <iostream>
#include<type_traits>
#include <vector>

using namespace std;

// 类似typedef定义函数指针
using func = int (*)(void); // --> typedef int (*func)(void);

// 定义模板别名
template <typename T>
using Ivetcor = vector<T>;

int main(void)
{
  Ivetcor<int> a {2, 3};

  if (is_same<decltype(a[0]), int>::value)
  {
    cout << "type is int" << '\n';
  }

  return 0;
}
