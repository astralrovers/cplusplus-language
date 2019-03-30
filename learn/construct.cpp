/******************************************    *******************************

      > File Name: construct.cpp

      > Author: Ywl

      > Descripsion:

      > Created Time:     Sun 27 May 2018 11:52:37 PM PDT

      > Modify Time: 

 *********************************    ***************************************/
#include <iostream>
#include <string>

class Test{
public:
    Test(){ /* 无参数时调用该构造函数 */
        std::cout << "Initial" << std::endl;
    }
    Test(const std::string cota){ /* 无参数时调用该构造函数 */
        cota_ = cota;
        std::cout << "Initial" << std::endl;
    }
    Test(const std::string cota, std::string name){ /* 有参数时调用 */
        std::cout << "Initial" << std::endl;
        cota_ = cota;
        name_ = name;
    }
    std::string get_name(void)
    {
        return name_;
    }
    ~Test(){
        std::cout << "Exit" << std::endl;
    }
    void set_name(std::string name)
    {
        name_ = name;
    }
private:
    const std::string cota_;
    std::string name_;
};

int main()
{
    Test a("person", "yu");
    std::cout << a.get_name() << std::endl;
    return 0;
}

