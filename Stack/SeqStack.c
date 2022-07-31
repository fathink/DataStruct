/*
    栈的顺序存储结构
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

/*-------- 定义栈的结构 --------*/
typedef struct
{
    ElemType data[MAXSIZE];
    int top;   //栈顶指针，-1表示栈底
}SeqStack;


//初始化栈
Status InitStatck(SeqStack *s)
{
    s->top = -1;
    return OK;
}

//入栈
Status push(SeqStack *s, ElemType e)
{
    if(s->top==MAXSIZE){
        return ERROR; //栈满返回ERROR
    }
    s->top++;
    s->data[s->top] = e;
    return OK;
}


//pop,出栈
Status pop(SeqStack *s, ElemType *e)
{
    if(s->top==-1)
    {
        return ERROR; //栈为空，返回ERROR
    }
    
    *e = s->data[s->top];  //返回栈顶元素
    s->top--;

    return OK;

}

void PrintStack(SeqStack *s)
{
    if(s->top == -1)
    {
        printf("Stack(%p) is NULL",s);
    }
    else
    {
        printf("Bottom");
        for(int i=0;i<=s->top;i++)
        {
            printf("->%d",s->data[i]);
        }
        printf("\n");
    }
    
}


int main()
{
    SeqStack s;
    Status flag;
    ElemType e;
    printf("%p\n",&s);
    flag = InitStatck(&s);

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