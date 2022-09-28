/*
    通用头文件定义
*/


#ifndef __STRING
#define  __STRING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


#define OK 1
#define ERROR 0
#define MAXSIZE 200
#define TRUE 1
#define FALSE 0

typedef int Bool;
typedef int Status;
// typedef int ElemType;

typedef char String[MAXSIZE+1]; // 定义字符串结构，第一位表示字符串长度

//构建String对象
Status StrAssign(String T, char *chars)
{
    if(strlen(chars)>MAXSIZE)
    {
        return ERROR;
    }
    else
    {
        T[0] = strlen(chars);
        for(int i=1;i<=T[0];i++)
        {
            T[i] = *(chars+i-1); //等价写法为chars[i-1]
        }
        return OK;
    }
}


#endif
