#include <iostream>

using namespace std;

int main(void)
{
  struct Astruct {
    int area1;
    int area2;
  };
  class Aclass {
  public:
    int field;
  };
  int *pt = new int; // 分配int大小的内存，注意和malloc一样是在堆上
  int *parray = new int[10]; // 数组
  struct Astruct *astr = new Astruct; // 结构体
  Aclass *aclass = new Aclass(); //对象

  *pt = 10;

  cout << "*pt = " << *pt << '\n';

  delete pt; // 和free一样，释放内存
  delete [] parray; // 释放数组必须这样释放
  delete astr;
  delete aclass;
}
