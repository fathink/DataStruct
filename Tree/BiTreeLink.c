/*
    二叉树操作
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef char ElemType;

//定义二叉树结构
typedef struct _BiTNode
{
    ElemType data;
    struct _BiTNode *lchild, *rchild; // 定义二叉树左右孩子
} BiTNode, *BiTree;

//创建二叉树
void CreateBiTree(BiTree *T)
{
    ElemType ch;
    scanf("%c", &ch);
}

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
    printf("OK\n");

    return 0;
}