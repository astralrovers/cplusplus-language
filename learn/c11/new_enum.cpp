#include <iostream>

using namespace std;

// 默认的enum是int型(导致可以和其他enum进行比较)，而且值不能相同

// 指定类型枚举
enum class newEnum : unsigned int {
  val1,
  val2,
  val3 = 100, // 值相同
  val4 = 100
};

// 用于打印枚举值
template <typename T>
std::ostream & operator <<(typename std::enable_if<std::is_enum <T>::value, 
    std::ostream>::type & stream, const T& e)
{
  return stream << static_cast<typename std::underlying_type <T>::type>(e);
}

int main(void)
{
  // 注意此时的val3不是数值，而是enum类型，不能和int或其他enum比较
  if (newEnum::val3 == newEnum::val4)
  {
    cout << "val3 == val4" << endl;
  }

  cout << newEnum::val3 << endl;

  return 0;
}
