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

//创建二叉树
void CreateBiTree(BiTree *T)
{
    ElemType ch;
    scanf("%c", &ch);
}

/*** 创建树 ***/
// CreatBiTree(BiTree *T)
// {
//     if(*T==NULL)
//     {
//         return NULL;
//     }
    
//     *T = (BiTree)malloc(sizeof(BiTNode));
//     CreatBiTree(*T);
// }


int main()
{
    int flag;
    BiTree T;  // 初始化一棵树
    char nodes[]="AB#C##DE###";

    // String s;
    // flag = StrAssign(s,"AB#C##DE###");
    // printf("%d\n",s[0]);
    // for(int i=0;i<s[0];i++){
    //     printf("%c",s[i+1]);
    // }

    // char t=nodes[0];
    int i=0;
    while(nodes[i]!='\0')
    {
        printf("%c",nodes[i]);
        i++;

    }
    
    


    return 0;
}