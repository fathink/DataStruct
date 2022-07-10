/*
    栈的链表存储结构
*/

#include <stdio.h>
#include <stdlib.h>
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

// 定义栈的结构
typedef struct _node
{
    ElemType data;
    struct _node *next;

}Node,*NodePtr;

typedef struct
{
    NodePtr top;  //栈顶指针，null表示栈底
    int count;  
}LinkStack;


//初始化栈
Status InitStatck(LinkStack *s)
{
    s->top = NULL;  // top指向null
    s->count = 0;
    return OK;
}

//判断栈是否为空
Bool StackEmpty(LinkStack *s){
    if(!(s->top)){
        return TRUE; // top非null说明栈非空
    }

    return FALSE;

}

void PrintStack(LinkStack *s)
{
    NodePtr top = s->top;
    if(top)
    {
        // printf("Top: ");
        for(int i=0;i<s->count;i++)
        {
            printf("%d<-",top->data);
            top = top->next;
        }
        printf("Bottom\n");
    }
    else
    {
        printf("Stack(%p) is NULL",s);

    }
    
}



//入栈
Status push(LinkStack *s, ElemType e)
{
    NodePtr node_ptr = (NodePtr)malloc(sizeof(Node));
    node_ptr->data = e;
    node_ptr->next = s->top;  //头插法

    s->top = node_ptr; // top指针指向新节点
    s->count++;
    return OK;
}


//pop,出栈
Status pop(LinkStack *s, ElemType *e)
{
    if(StackEmpty(s))
    {
        return ERROR; //栈为空，返回ERROR
    }
    NodePtr p = s->top;

    *e = s->top->data;
    s->top = s->top->next; // top指向下一个节点   
    s->count--;

    free(p); // 释放出栈的内存

    return OK;

}

int main()
{
    LinkStack s;
    Status flag;
    ElemType e;
    printf("%p\n",&s);
    flag = InitStatck(&s);
    // PrintStack(&s);

    //入栈
    flag = push(&s,3);
    flag = push(&s,4);
    flag = push(&s,5);
    flag = push(&s,6);
    flag = push(&s,7);
    PrintStack(&s);
    
    //出栈
    flag = pop(&s,&e);
    printf("Stack(%p) pop=%d, current: ",&s,e);
    PrintStack(&s);

    flag = pop(&s,&e);
    printf("Stack(%p) pop=%d, current: ",&s,e);
    PrintStack(&s);

    flag = pop(&s,&e);
    printf("Stack(%p) pop=%d, current: ",&s,e);
    PrintStack(&s);

    flag = pop(&s,&e);
    printf("Stack(%p) pop=%d, current: ",&s,e);
    PrintStack(&s);

    flag = pop(&s,&e);
    printf("Stack(%p) pop=%d, current: ",&s,e);
    PrintStack(&s);

    return 0;
}