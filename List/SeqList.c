/*
    线性表链式存储结构实现
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

//定义顺序表结构
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;


/**--------创建顺序存储链表------------**/
Status InitList(SeqList *L, int n)
{
    (*L).length = 0;
    for(int i=0;i<n;i++)
    {
        (*L).data[i] = i+1;
        (*L).length++;
    }
    return OK;
}

/**--------获取顺序列表元素------------**/
Status GetElem(SeqList L, int i, ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
        return ERROR;
    
    *e = L.data[i-1];
    return OK;
}

/**--------顺序列表元素插入&删除---------**/

//打印顺序链表
void PrintList(SeqList L)
{
    printf("Print SeqList(%p): head[0]",&L);
    for(int i=0;i<L.length;i++)
    {
        printf("->%d",L.data[i]);
    }
    printf(",length=%d\n",L.length);
}

int main()
{
    
    SeqList L;

    //初始化链表
    Status flag;
    flag = InitList(&L,10);
    printf("\n初始化链表,Status=%d,",flag);
    PrintList(L);

    //获取第i个元素
    int i = 1;
    ElemType e=0;
    flag = GetElem(L,i,&e);
    printf("\n获取第%d个元素,Status=%d,元素值=%d",i,flag,e);
}

