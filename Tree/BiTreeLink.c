/*
    二叉树操作
*/

#include "../include/general.h"


typedef char ElemType;

/**------ 定义二叉树结构----------**/
typedef struct _BiTNode
{
    ElemType data;
    struct _BiTNode *lchild, *rchild; // 定义二叉树左右孩子
} BiTNode, *BiTree;



/**--------定义栈结构-----------**/
typedef struct _Stack
{
    BiTree data[MAXSIZE];
    int top;  //栈顶指针，-1表示栈低
    
}Stack;

//进栈
Bool push(Stack *stack, BiTree data)
{
    if(stack->top==MAXSIZE)
    {
        return FALSE;
    }
    stack->top++;
    stack->data[stack->top] = data;
    return TRUE;
}

//出栈
Bool pop(Stack *stack, BiTree *data)
{
    if(stack->top == -1)
    {
        return FALSE; //栈空
    }

    *data = stack->data[stack->top];
    stack->top--;
    return TRUE;
}


/* -------- 二叉树相关操作 ---------- */

/** ----------- 前序的方式创建树---------- **/
char nodes[]="AB#C##DE###"; // 定义全局变量，用于构建树
int idx=0;

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

/** -------- 前序遍历二叉树 -------- **/
void PreOrderTraverse(BiTree T) // 递归方式遍历树
{
    if(T==NULL)
    {
        return;
    }
    printf("%c",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void PreOrderTraverseByStack(BiTree T) //非递归方式遍历树
{
    printf("\nPreOrderTraverseByStack T=%p,&T=%p\n",T,&T);
    if(T==NULL)
    {
        return;
    }
    Bool flag;
    
    Stack stack;
    stack.top=-1; // 栈初始化
    flag = push(&stack, T); // 根节点先入栈

    while(stack.top != -1)
    {
        flag = pop(&stack, &T); // 根结点出栈
        printf("%c",T->data);

        // 右子树入栈
        if(T->rchild != NULL)
        {
            flag = push(&stack, T->rchild);
        }

        //左子树入栈
        if(T->lchild != NULL)
        {
            flag = push(&stack, T->lchild);
        }
    }
    printf("\n");
}

/** -------- 中序遍历二叉树 -------- **/
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

/** -------- 后续遍历二叉树 -------- **/
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
    printf("\t");
    PreOrderTraverseByStack(T);
    
    printf("中序遍历结果: ");
    MidOrderTraverse(T);
    printf("\n");

    printf("后序遍历结果: ");
    PostOrderTraverse(T);
    printf("\n");
    return 0;
}