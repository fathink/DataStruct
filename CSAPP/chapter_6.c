/*
 * 第六章：存储器层次结构
 *
 * 测试高速缓存命中实验
 * 
 * 
*/

#include <stdio.h>
#include <time.h>

#define N 1000
int Mat[N][N] = {1};

int sum_by_row(int m[N][N])
{
    int i,j,sum;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            sum += m[i][j];

    return sum;
}

int sum_by_col(int m[N][N])
{
    int i,j,sum;
    for(j=0;j<N;j++)
        for(i=0;i<N;i++)
            sum += m[i][j];

    return sum;
}


int main()
{   
    int res;
    clock_t start,end;

    //按照行遍历矩阵
    start = clock();
    res = sum_by_row(Mat);
    end = clock();
    printf("sum by row cost time = %lu ms\n",end-start);

    //按照列遍历矩阵
    start = clock();
    res = sum_by_col(Mat);
    end = clock();
    printf("sum by col cost time = %lu ms\n",end-start);

    //注：c语言矩阵式按照行方式进行构建的，因此按照行的方式进行遍历，
    // 更容易命中到高速缓存，整体执行的结果应该更快


    return 0;
    
}