#include <stdio.h>
#include <iostream>


enum class new_def {
    MAX_LEN___ = 90
};

enum { MAX_LEN___ = 6 };

class Test {
    public:
        enum { MAX_LEN = 5 };

        // 直接使用MAX_LEN
        int scores[MAX_LEN];

};

int main(void)
{
    // 这个是无法使用的
    // std::cout << MAX_LEN << std::endl;
    std::cout << Test::MAX_LEN << std::endl;
    // 由于cout不支持输出enum class类型，所以要强制转换
    std::cout << static_cast<int>(new_def::MAX_LEN___) << std::endl;
    std::cout << MAX_LEN___ << std::endl;
    return 0;
}
