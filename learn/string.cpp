#include <iostream>
#include <string>
#include <vector>
#include <cwchar>

using namespace std;

int main(void)
{
  // string用起来相对方便，有许多高级特性，而且不用担心越界，一般字符串处理的话就用它
  string str1 = "hello";
  string str2 = str1;

  cout << "string size = " << sizeof(string) << endl;
  cout << "str size = " << sizeof(str1) << endl;

  cout << "str1 == str2 ? " << ((str1 == str2) ? "true" : "false") << endl;

  cout << "str addr = [" << hex << &str1 << "]" << " str2 addr = [" << hex << &str2 << "]" << endl;

  str2 += " world";
  cout << str1 << endl;
  cout << str2 << endl;
  // 我们可以发现string是基本数据类型，并非封装过的指针，因为他们的地址不一样

  //string strL = L"wchar_t";
  //string stru = u"char_16";
  //string strU = U"char_32";
  //string stru8 = u8"char_utf-8";

  // 指定不同长度的字符串
  wchar_t strL[] = L"wchar_t";
  char16_t stru[] = u"char_16";
  char32_t strU[] = U"char_32";
  char stru8[] = u8"char_utf-8";

  // cout << R"hello "\n" world" << '\n'; // R表示输出原始字符串raw，中介的仍和字符串都不用转义，但是这是C++11新特性，g++可能不支持
  cout << strL << '\n';
  cout << stru << '\n';
  cout << strU << '\n';
  cout << stru8 << '\n';

  return 0;
}
