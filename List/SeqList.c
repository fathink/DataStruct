/*
线性表顺序存储
*/
#define OK 1;
#define ERROR 0;

typedef int Status;


#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

/* 获取顺序列表元素*/
Status GetElem(SqList L, int i, ElemType *e)
{
    if(L.length==0 || i<0 || i>L.length)
        return ERROR
    *e=L.data[i];
    return OK
}