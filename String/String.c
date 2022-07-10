/*
    字符串操作
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0


typedef int Bool;
typedef int Status;
typedef int ElemType;

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
            T[i] = *(chars+i-1);
        }
        return OK;
    }
}

Status PrintString(String T)
{
    for(int i=0;i<T[0];i++){
        printf("%c",T[i+1]);
    }
    return OK;
}

int main()
{
    String s;
    Status flag;
    flag = StrAssign(s,"中文");

    PrintString(s);

    return 0;
}