/*
    二叉树操作
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


typedef int ElemType;

//定义二叉树结构
typedef struct _BiTNode
{
    ElemType data;
    struct _BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


//创建树
CreatBiTree(BiTree *T)
{
    if(*T==NULL)
    {
        return NULL;
    }
    
    *T = (BiTree)malloc(sizeof(BiTNode));
    CreatBiTree(*T);
}


int main()
{
    printf("\nOK\n");
    return 0;
}