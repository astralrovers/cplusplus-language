#include <iostream>
#include <string>
#include <vector>
#include <array>
/* 使用的是using编译指令,同名不会导致冲突，如果全局变量定义一个相同的，那么命名空间的会被覆盖,
 * 如果使用using声明会报错，不能存在同名的
 * */
using namespace std;        /* 最好不要使用这种方法 会导入所有内容
                                using std::cout;
                                */
/* 自定义一个名称空间 */
namespace pri_space{
    int max_num = 1024;
    int my_age = 23;
    void print_max_num(void){
        std::cout << "max_num : " << max_num << std::endl;
    }
    class Person{
    public:
        int time = 0;
        int get_cur_time(void);
    };
}

// 两个相同的命名空间，是用于扩展
namespace pri_space{
    int Person::get_cur_time(void)
    {
        return this->time;
    }
}
/*
int pri_space::Person::get_cur_time(void)
{
    return this->time;
}
*/

// 像这种类定义，函数，变量声明就可以放在头文件里
namespace little_sp{
    enum{
        MAX_NUMBER = 1024,
    };
    extern std::string version;
    void print_name(const std::string name);
    void get_name(std::string &ver);
}

namespace little_sp{
    std::string version = "v1.1";
    void print_name(const std::string name){
        std::cout << name << std::endl;
    }
    void get_name(std::string &ver){
        ver = version;
    }
}

namespace othername = little_sp; // 可以取别名

// 匿名命名空间
namespace {
    int my_name = 34;
}

/* 使用的是using声明, 全局中的声明，有同名的会报错 */
//using pri_space::max_num;
int max_num = 1023;

int main(int argc, char ** argv)
{
	cout << "namespace" << endl;
    cout << "匿名命名空间，相当于static变量，只在本文件内使用" << my_name << endl;
    //类似作用域
    using pri_space::print_max_num;
    using pri_space::max_num;   //局部作用域中声明不会报错，会覆盖全局变量

    cout << "print max num" << max_num << endl;
    print_max_num();

    // ::使用的是全局变量
    cout << "print gloab max num" << ::max_num << endl;//使用全局变量

    // using pri_space::my_age; // 这里会导致冲突
    // 会发现在全局导入同名变量会与全局变量冲突，在局部导入会与局部变量冲突
    using namespace pri_space;
    int my_age = 18;
    cout << "print local max num" << my_age << endl; // 这时会使用局部的同名变量，using导入的有点类似于全局变量


#if 0
	char new_len = 10;
	char *test_array = new char[new_len];
	delete [] test_array;

	/* vector 用于动态增长，使用new管理，堆内存，用于数组的话开销较大 */
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	cout << v.size() << endl;

	v.clear();
	cout << v.size() << endl;
	
	vector<char> v2(4);//这个是可以变量设置的
	cout << v2.size() << endl;
	v2.clear();
	cout << v2.size() << endl;

	/* 数组大小设置时必须固定 */
	array<char, 4> array1 = {1, 2, 3, 4};
	array<char, 4> array2 = array1;
	char buf[4] = {1, 2, 3, 4};

	for(char index : buf)
	{
		cout << index << endl;//打印不出来?
	}

#endif
	return 0;
}


