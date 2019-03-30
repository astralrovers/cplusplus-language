/******************************************    *******************************

      > File Name: a.cpp

      > Author: Ywl

      > Descripsion:

      > Created Time:     Sun 27 May 2018 10:20:14 PM PDT

      > Modify Time: 

 *********************************    ***************************************/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class test{
private:
    int year = 2018;
public:
    void print_name(void);
};

void test::print_name(void)
{
    printf("ywl");
}


int main()
{
    printf("%ld\n", sizeof(class test));
    return 0;
}
