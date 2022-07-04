/*
    线性表链式存储结构实现

*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"


#define OK 1;
#define ERROR 0;

typedef int Status;

//定义Node结构
typedef int ElemType;
typedef struct _node   // 采用typedef的方式使得 struct _node 和 Node等价
{
    ElemType data;
    struct _node *next;  //不能使用Node，因为执行到该处是Node还未定义
}Node;
typedef Node *LinkList; // LinkList等价于struct Node *


Status InitList(LinkList L)
{
    L = (LinkList)malloc(sizeof(Node));
    if(!(L))
    {
        return ERROR; // 初始化失败
    }
    (L)->next = NULL;
    return OK

}

/**--------创建单链表------------*/
void CreateListHead(LinkList *L, int n){
    //头插法创建单链表
    LinkList p;
    *L = (LinkList)malloc(sizeof(Node));

    for(int i=0;i<n; i++){


    }



}


void PrintList(LinkList p){
    while(p){
        printf("%s",p->data);
        p = p->next;
    }
}

int main(){
    
    LinkList L;
    
    Status flag;
    flag = InitList(L);
    
    
    
    printf("OK");
    


}