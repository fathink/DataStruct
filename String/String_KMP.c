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
            T[i] = *(chars+i-1); //等价写法为chars[i-1]
        }
        return OK;
    }
}

Status PrintString(String T)
{
    for(int i=0;i<T[0];i++){
        printf("%c",T[i+1]);
    }
    printf("\n");
    return OK;
}

/*返回子串T在主串S中第pos个字符之后的位置，如果不存在则返回零*/
int Index(String S, String T, int pos)
{
    int i = pos;  //遍历主串的索引，从pos的位置遍历主串S
    int j = 1; //遍历字串T的索引

    int iter = 0;
    while(i <= S[0] && j <= T[0])
    {
        printf("Iter=%d,S[%d]=%c,T[%d]=%c\n",++iter,i,S[i],j,T[j]);
        if(S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i-j+2;  //i退回到上次首次匹配的下一个字符串
            j = 1;    //j退回到子串T的首位
        }
    }
    
    if(j > T[0])
    {
        return i - T[0];  //匹配到字符串，返回对应的索引
    }
    else
    {
        return 0;
    }
}

void get_next(String T, int *next)
{
    int i,k;
    i = 1;
    k = 0;
    next[1]  = 0;

    while (i < T[0])  // T[0]表示字符串长度
    {
        /* code */
    }
    
}

int main()
{
    String s,t;
    Status flag;
    flag = StrAssign(s,"goodgoogle");
    flag = StrAssign(t,"googled");

    PrintString(s);
    PrintString(t);

    int idx;
    idx = Index(s,t,2);
    printf("%d",idx);

    return 0;
}