/******************************************    *******************************

      > File Name: namesp.cpp

      > Author: Ywl

      > Descripsion:

      > Created Time:     Fri 25 May 2018 01:50:29 AM PDT

      > Modify Time: 

 *********************************    ***************************************/
#include <iostream>
#include "namesp.h"

namespace little_sp{
    std::string version = "v1.1";
    void print_name(const std::string name){
        std::cout << name << std::endl;
    }
    void get_name(std::string &ver){
        ver = version;
    }
}
