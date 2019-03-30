/******************************************    *******************************

      > File Name: point.c

      > Author: Ywl

      > Descripsion:

      > Created Time:     Sun 27 May 2018 10:28:21 PM PDT

      > Modify Time: 

 *********************************    ***************************************/

#include <stdio.h>


char *get_name(void)
{
    //char name[3] = "yu";
    char *name = "yu";
    return name;
}

int main()
{
    char *name;
    name = get_name();
    printf("%s\n", name);
    return 0;
}
