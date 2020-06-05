#include <iostream>


class Init1 {
	private:
		int a;
		const int b;

	public:
		Init1(int a, const int b) : b(b) {  // 对于b而言使用的是初始化列表，这种方式是十分搞笑的，它在构造函数执行之前，而且const必须用这样的方式
			a = a;  // 对于b而言，其实是赋值
		}
};


int main(void)
{
	if (1)
	{

	}
	return 0;
}
