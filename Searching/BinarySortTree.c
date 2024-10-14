/*
    二叉排序树，（Binary Sort Tree），又称为二叉查找树，左子树的值均小于根节点，右子树的值均大于根节点；
*/

#include "../include/general.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <time.h>

typedef struct BiTNode
{
    int data; // 节点数据
    struct BiTNode *lchild, *rchild; //左右节点
}BiTNode, *BiTree;




/*
    二叉排序树查找逻辑
    T: 二叉树根节点指针
    key： 待查找对象
    f：一般是T的双亲节点，递归的时候使用，
    p: 记录查找成功时，可以获取对应节点的位置
*/
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if(!T)
    {
        *p = f;
        return FALSE;
    }

    else if (key == T->data)
    {
        *p = T;  // 查找成功，记录节点地址
        return TRUE;
    }

    else if (key < T->data)  //如果key小于当前节点，往左节点查找
        return SearchBST(T->lchild, key, T, p);

    else 
        return SearchBST(T->rchild, key, T, p);
}

/*
    二叉排序树插入逻辑
    T: 二级指针，这里传入二级指针原因是要修改原始T指向的地址
    key： 待插入对象
*/

Status InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    
    if(!SearchBST(*T, key, NULL, &p)) // 没有查找到
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;

        if(!p)
            *T = s; //p是空节点，说明T是空树，此时s为根节点
        else if (key < p->data)
            p->lchild = s;  // key比节点数值小，赋值为左节点
        else
            p->rchild = s;
        
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

int main()
{
    BiTree T=NULL;
    int a[10] = {62,88,58,47,35,73,51,99,37,93};
    for(int i=0; i<10;i++)
    {
        InsertBST(&T,a[i]);
    }
    printf("OK\t%p\t%p\n",&T,T);
}