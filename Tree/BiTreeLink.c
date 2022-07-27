/*
    二叉树操作
*/

#include "../include/general.h"


typedef char ElemType;

//定义二叉树结构
typedef struct _BiTNode
{
    ElemType data;
    struct _BiTNode *lchild, *rchild; // 定义二叉树左右孩子
} BiTNode, *BiTree;

char nodes[]="AB#C##DE###"; // 定义全局变量，用于构建树
int idx=0;

//创建二叉树
void CreateBiTree(BiTree *T)
{
    ElemType ch;
    scanf("%c", &ch);
}

/*** 前序的方式创建树 ***/
void CreatBiTree(BiTree *T)
{
    //防止无穷遍历字符串数组
    if(nodes[idx]=='\0')
    {
        return;
    }
  
    char ch = nodes[idx++];
    if(ch=='#')
    {
        *T=NULL;
    }
    else{

        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        CreatBiTree(&(*T)->lchild);
        CreatBiTree(&(*T)->rchild);
    }
}

// 前序遍历二叉树
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
    {
        return;
    }
    printf("%c",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//中序遍历二叉树
void MidOrderTraverse(BiTree T)
{
    if(T==NULL)
    {
        return;
    }
    MidOrderTraverse(T->lchild);
    printf("%c",T->data);
    MidOrderTraverse(T->rchild);
}

//后序遍历二叉树
void PostOrderTraverse(BiTree T)
{
    if(T==NULL)
    {
        return;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c",T->data);
}


int main()
{
    int flag;
    BiTree T; 
    T=NULL;  // 初始化为空指针

    // 创建二叉树
    printf("T=%p,&T=%p\n",T,&T);
    CreatBiTree(&T);
    printf("T=%p,&T=%p\n",T,&T);

    printf("前序遍历结果: ");
    PreOrderTraverse(T);
    printf("\n");
    
    printf("中序遍历结果: ");
    MidOrderTraverse(T);
    printf("\n");

    printf("后序遍历结果: ");
    PostOrderTraverse(T);
    printf("\n");
    return 0;
}