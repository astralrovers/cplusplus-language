/******************************************    *******************************

      > File Name: namessp.cpp

      > Author: Ywl

      > Descripsion:

      > Created Time:     Fri 25 May 2018 01:56:30 AM PDT

      > Modify Time: 

 *********************************    ***************************************/

#include <iostream>
#include "namesp.h"

int main()
{
    little_sp::print_name("ywl");
    std::string ver;
    little_sp::get_name(ver);
    std::cout << ver << std::endl;
    std::cout << little_sp::version << std::endl;
    return 0;
}
