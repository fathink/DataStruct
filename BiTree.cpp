#include <iostream>
typedef char ElemType;
using namespace std;

//定义一个二叉树结点
typedef struct BiTNode{
	ElemType data;
	BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//初始化树,按照前序遍历方式输入
void CreatBinaryTree(BiTree *T){
	ElemType e = cin.get();
	if (e == ' '){
		*T = NULL; 
	}
	else{
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data = e;
		CreatBinaryTree(&(*T)->lchild);
		CreatBinaryTree(&(*T)->rchild);
	}
}

//前序遍历
void PreOrderTraverse(BiTree T, int level){
	if (T){
		cout << T->data << " level is " << level << endl;
		PreOrderTraverse(T->lchild, level+1);
		PreOrderTraverse(T->rchild, level+1);
	}
}

//中序遍历
void MidOrderTraverse(BiTree T, int level){
	if (T){
		MidOrderTraverse(T->lchild, level + 1); //左结点
		cout << T->data << " level is " << level << endl;
		MidOrderTraverse(T->rchild, level + 1); //右节点
	}
}

//后序遍历
void ReaOrderTraverse(BiTree T, int level){
	if (T){
		ReaOrderTraverse(T->lchild, level + 1); //左结点
		ReaOrderTraverse(T->rchild, level + 1); //右节点
		cout << T->data << " level is " << level << endl;
	}
}
int main(){
	int level = 1;
	BiTree T = NULL;
	cout << "输入一颗二叉树（前序遍历方式）："<<endl;
 	CreatBinaryTree(&T);//AB C  DE   |
	cout << "前序遍历二叉树:\n";
	PreOrderTraverse(T, level);
	cout << "中序遍历二叉树:\n";
	MidOrderTraverse(T, level);
	cout << "后序遍历二叉树:\n";
	ReaOrderTraverse(T, level);

}

