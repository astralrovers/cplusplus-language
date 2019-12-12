#include <memory>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct CopyTest {
	int a_;
	int b_;
};

int main(void)
{
	vector<shared_ptr<struct CopyTest>> _list;
	
	_list.push_back(shared_ptr<struct CopyTest>(new struct CopyTest));
	_list.push_back(shared_ptr<struct CopyTest>(new struct CopyTest));
	_list.push_back(shared_ptr<struct CopyTest>(new struct CopyTest));
	_list.push_back(shared_ptr<struct CopyTest>(new struct CopyTest));

	_list[0]->a_ = 1;
	_list[0]->b_ = 2;

	_list[1]->a_ = 3;
	_list[1]->b_ = 4;

	_list[2]->a_ = 5;
	_list[2]->b_ = 6;

	_list[3]->a_ = 7;
	_list[3]->b_ = 8;

	struct CopyTest *b = new struct CopyTest;

	//copy(b, b + 1, &*_list[2]);
	memcpy(b, &*_list[2], sizeof(struct CopyTest));

	cout << b->a_ << ", " << b->b_ << endl;

	b->a_ = 90;
	b->b_ = 100;

	//copy(&*_list[2], &*_list[2] + 1, b);
	memcpy(&*_list[2], b, sizeof(struct CopyTest));

	cout << _list[2]->a_ << ", " << _list[2]->b_ << endl;

	delete b;

	return 0;
}
