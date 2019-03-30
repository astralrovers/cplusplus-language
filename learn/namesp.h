/******************************************    *******************************

      > File Name: namesp.h

      > Author: Ywl

      > Descripsion:

      > Created Time:     Fri 25 May 2018 01:45:48 AM PDT

      > Modify Time: 

 *********************************    ***************************************/

#ifndef _NAMESP_H
#define _NAMESP_H

#include <string>

namespace little_sp{
    enum{
        MAX_NUMBER = 1024,
    };
    extern std::string version;
    void print_name(const std::string name);
    void get_name(std::string &ver);
}

#endif
