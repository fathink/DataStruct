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

/* ----------- 前序的方式创建树---------- 
         A
      /     \    
     B       D
      \     /
       C   E
 **/
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
    // printf("\nPreOrderTraverseByStack T=%p,&T=%p\n",T,&T);
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
void InOrderTraverse(BiTree T)
{
    if(T==NULL)
    {
        return;
    }
    InOrderTraverse(T->lchild);
    printf("%c",T->data);
    InOrderTraverse(T->rchild);
}

void InOrderTraverseByStack(BiTree T) // 非递归方式中序遍历树
{
    // 1、如果栈顶元素非空且左节点存在，将其入栈，重复该过程。若不存在则进入第2步
    // 2、若栈非空，输出栈顶元素并出栈。判断刚出栈的元素的右节点是否存在，不存在重复第2步，存在则将右节点入栈，跳至第1步
    if(T==NULL)
    {
        return;
    }

    Bool flag;
    Stack stack;
    stack.top = -1;

    flag = push(&stack, T);
    BiTNode top;

    while(stack.top != -1)
    {
        //step 1
        while(stack.data[stack.top]->lchild != NULL)  // stack.data[stack.top]表示栈顶元素
        {
            flag = push(&stack, stack.data[stack.top]->lchild);
        }

        //step2
        //while循环会一直将栈顶输出，直到遇到有右节点的节点，这样能保证栈中元素不会重复寻找左孩子
        while(stack.top != -1)
        {
            flag = pop(&stack, &T);
            printf("%c",T->data);
            
            if(T->rchild != NULL)
            {
                flag = push(&stack,T->rchild);
                break;
            }
        }

    }
    printf("\n");
    
}



/** -------- 后序遍历二叉树 -------- **/
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

void PostOrderTraverseByStack(BiTree T) //非递归方式后序遍历二叉树
{
    if(T==NULL)
    {
        return;
    }

    Bool flag;
    BiTree last_node=NULL;
    Stack stack;
    stack.top = -1; //栈的初始化

    flag = push(&stack, T);  //根节点入栈
    while (stack.top != -1)
    {
        //左子树非空一直push
        while(stack.data[stack.top]->lchild != NULL)
        {
            flag = push(&stack, stack.data[stack.top]->lchild);
        }
        
        //相比中序遍历，后序遍历需要判断上次出栈的元素是否是右节点
        while(stack.top != -1){
            BiTree top = stack.data[stack.top]; //栈顶元素
            if(top->rchild == last_node || top->rchild == NULL)  //上次输出的元素是右节点或者右节点为空，出栈
            {
                flag = pop(&stack, &T);
                printf("%c",T->data);

                last_node = T; // 记录本次出栈元素
            }
            else if (top->rchild != NULL)
            {
                flag = push(&stack, top->rchild);
                break;
            }
            
        }
    }
    printf("\n");

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
    InOrderTraverse(T);
    printf("\t");
    InOrderTraverseByStack(T);

    printf("后序遍历结果: ");
    PostOrderTraverse(T);
    printf("\t");
    PostOrderTraverseByStack(T);
    
    return 0;
}