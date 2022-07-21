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

//构造KMP算法next数组
void get_next(String T, int *next)
{
    int i,k;
    i = 1;
    k = 0;
    next[1]  = 0;

    while (i<T[0]) // T[0]表示字符串长度
    {
        if( k == 0 || T[i] == T[k])
        {
            ++i;
            ++k;
            next[i] = k;
        }
        else
        {
            k = next[k]; //如果字符不相同，对k进行回溯
        }

    }    
}

/*
 * KMP算法实现字符串匹配函数
 * 返回子串T在主串S中第pos个字符之后的位置，如果不存在则返回零
 */
int Index_KMP(String S, String T, int pos)
{

    int i = pos;
    int j = 1;
    int next[T[0]+1];
    get_next(T, next);
    
    //主循环
    while (i <= S[0] && j <= T[0])
    {
        if(j==0 || S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];  //对j进行回溯
        }
    }

    if(j>T[0])
    {
        return i - T[0]; //匹配到字符串，返回对应的索引
    }
    else
    {
        return 0;
    }

}

int main()
{
    String s,t;
    Status flag;
    flag = StrAssign(s,"abaaacdef");
    flag = StrAssign(t,"aaa");

    PrintString(s);
    PrintString(t);

    int idx;
    // idx = Index(s,t,2);

    // 测试KMP算法
    idx = Index_KMP(s,t,1);
    printf("%d",idx);

    return 0;
}