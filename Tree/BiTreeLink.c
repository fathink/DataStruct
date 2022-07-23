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
    struct _BiTNode *lchild, *rchild; // 定义二叉树左右孩子
} BiTNode, *BiTree;

int main()
{
    printf("OK");
    return 0;
}