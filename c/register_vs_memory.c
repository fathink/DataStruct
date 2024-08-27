/*
* 测试
*/

#include <time.h>
#include <stdio.h>

#define NUM 1000000000

int m,n = NUM;   //全局变量

int main()
{
    clock_t start, end;

    register int r_a,r_b = NUM;  //寄存器变量
    int m_a, m_b = NUM; //普通变量，存在内存中

    // 寄存器操作变量性能
    start = clock();
    for (r_a=0; r_a<r_b; r_a++);
    end = clock();
    printf("Registers cost time=%.6f s\n",(end-start)*1.0/CLOCKS_PER_SEC);

    // 内存操作变量性能
    start = clock();
    for (m_a=0; m_a<m_b; m_a++);
    end = clock();
    printf("Memory cost time=%.6f s\n",(end-start)*1.0/CLOCKS_PER_SEC);


    return 0;

}
