#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main(void)
{
  // vector类似于string是自动增长的
  // 格式：vector<typename> vt(n_elem)
  // vector有一组函数来操作它，不过相对于普通数组来说操作会更慢，但是更安全，扩展性更好
  vector<int> vt; // 创建0个元素的int数组

  int n = 100;
  vector<int> vt2(n); // 创建100个元素的int数组

  // array是固定大小的，和普通数组类似，不过更安全
  array<int, 5> at = {1, 2}; // 5个元素的int数组
  // array<int, 10> at2 = { [0 ... 10-1] = 10 }; // 不支持这种初始化方法，不是正常数组

  at[3] = 10;
  at[-1] = 90;

  return 0;
}
