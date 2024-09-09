/*
 * 第三章：程序的机器级表示
 *
 * 指针函数测试
 * 
 * 
*/

#include <stdio.h>

#define N 10
int Data[N][N];

int fun(int x, int *y)
{
    int res;
    res = x + (*y);
    return res;

}


int fun_point()
{
    
    int (*fp)(int, int*);  //定义函数指针
    fp=fun;   //指针赋值


    printf("%p",fp);

    int a = 3;
    int b =5;

    return 0;
}


int main()
{
    
    int s = fun_point();
    return 0;
    
}