/*
    线性表链式存储结构实现

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


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

/**--------链表初始化-------------**/
Status InitList(LinkList *head)
{
    *head = (LinkList)malloc(sizeof(Node));  // head指针指向malloc分配的地址
    if(!(*head))
    {
        return ERROR; // 初始化失败
    }
    (*head)->next = NULL;
    return OK;

}

/**--------创建单链表与删除------------*/
//头插法创建单链表
void CreateListHead(LinkList *head, int n){
    LinkList p;
    *head = (LinkList)malloc(sizeof(Node)); //建立头节点
    (*head)->next = NULL;

    srand(time(0));
    for(int i=0;i<n; i++){
        p = (LinkList)malloc(sizeof(Node));
        // p->data = rand()%100+1; // 随机生成100以内的数据
        p->data = i+1; // 随机生成100以内的数据

        p->next = (*head)->next;
        (*head)->next = p;  // 插入到表头
    }
}

//尾插法创建单链表
void CreateListTail(LinkList *head, int n)
{
    LinkList p,t;
    *head = (LinkList)malloc(sizeof(Node));
    (*head)->next = NULL;
    t=*head;

    for(int i=0;i<n;i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = i+1;

        t->next = p; //链表尾部指向p
        t = p;
    }
    t->next = NULL;
}

/**---------单链表插入&删除元素-----------**/
// 第i个位置后插入元素e
Status ListInsert(LinkList *L, int i, ElemType e)  
{
    LinkList p,q;
    p = *L;

    int j = 1;
    p = p->next;  //指向第一个节点
    while(p && j<i)
    {
        p = p->next;
        ++j;
    }

    if(!p || j>i)
    {
        return ERROR; //第i个元素不存在
    }

    q = (LinkList)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK
}

//删除第i个位置的元素
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    LinkList p,q;
    p = *L;

    // p = p->next;
    int j = 1;  //从第一个位置开始找
    while(p->next && j<i)
    {
        p = p->next;
        ++j;
    }

    if(!(p->next) || j>i)
    {
        return ERROR;
    }

    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);

    return OK;
}

//删除整个链表
Status ClearList(LinkList L)
{
    LinkList p,q;
    p=(L)->next;
    while(p)
    {
        q = p->next; //记住下一个节点
        free(p);
        p = q;
    }
    (L)->next = NULL; // 头节点指针域为空
    return OK;
}

void PrintList(LinkList p){
    printf("Print LinkList(%p): head[%d]",p,p->data);
    p = p->next;
    int length = 0;
    while(p){
        printf("->%d",p->data);
        p = p->next;
        ++length;
    }
    printf(",length=%d\n",length);
}

int main(){
    
    LinkList L;

    //初始化链表
    Status flag;

    printf("\n初始化链表");
    flag = InitList(&L);
    printf(",初始化状态=%d,head address=%p",flag,L);
    PrintList(L);
    
    printf("\n[创建链表] 头插法创建链表 ");
    CreateListHead(&L,5);
    PrintList(L);

    printf("\n[创建链表] 尾插法创建链表 ");
    CreateListTail(&L,6);
    PrintList(L);

    //插入元素
    int i = 6;
    ElemType e = 99;
    flag = ListInsert(&L,i,e);
    printf("\n[插入元素] 在第%i个元素后插入元素%d,Status=%d,",i,e,flag);
    PrintList(L);

    //删除元素
    i = 8;
    e = 0;
    flag = ListDelete(&L,i,&e);
    printf("\n[删除元素] 删除第%d个元素,被删除元素=%d,Status=%d,",i,e,flag);
    PrintList(L);


    
    ClearList(L);
    printf("\n[销毁链表]");
    PrintList(L);

}