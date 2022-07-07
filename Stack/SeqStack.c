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

typedef struct
{
    ElemType data[MAXSIZE];
    int top;   //栈顶指针，-1表示栈底
}SeqStack;


//初始化栈
Status InitStatck(SeqStack *s)
{
    s->top = -1;
}

//pop,入栈
Status pop()

int main()
{
    SeqStack s;
    Status flag;
    flag = InitStatck(&s);




}