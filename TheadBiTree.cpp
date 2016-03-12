#include <iostream>
using namespace std;

typedef char ElemType;
typedef enum { Link, Thread }PointerNag;//定义状态变量


//定义一个二叉树结点
typedef struct ThreadBiTNode{
	ElemType data;
	ThreadBiTNode *lchild, *rchild;
	PointerNag ltag;
	PointerNag rtag;
}ThreadBiTNode, *ThreadBiTree;

ThreadBiTree pre; //pre是一个全局变量
//初始化树,按照前序遍历方式输入
void CreatBinaryTree(ThreadBiTree *T){
	ElemType e = cin.get();
	if (e == ' '){
		*T = NULL;
	}
	else{
		*T = (ThreadBiTNode*)malloc(sizeof(ThreadBiTNode));
		(*T)->data = e;
		(*T)->ltag = Link;
		(*T)->rtag = Link;
		CreatBinaryTree(&(*T)->lchild);
		CreatBinaryTree(&(*T)->rchild);
	}
}

//中序遍历线索化
void MidOrderTraverse(ThreadBiTree T){
	if (T){
		MidOrderTraverse(T->lchild); //左结点
		if (!T->lchild){
			T->ltag = Thread;
			T->lchild = pre;
		}
		if (!pre->rchild){
			pre->rtag = Thread;
			pre->rchild = T;
		}
		pre = T;
		//cout << T->data << " level is " << level << endl;
		MidOrderTraverse(T->rchild); //右节点
	}
}

//中序遍历线索化初始操作
void InOrderThread(ThreadBiTree *p, ThreadBiTree T){
	*p = (ThreadBiTNode *)malloc(sizeof(ThreadBiTNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if (!T){
		(*p)->lchild = *p;
	}
	else{
		(*p)->lchild = T;
		pre = *p;
		MidOrderTraverse(T);
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}
}




//中序输出二叉树（非递归形式）
void MidOutputBiTree(ThreadBiTree T){
	ThreadBiTree p;
	p = T->lchild;
	while (p!= T){   //空树或者遍历结束时
		while (p->ltag == Link){
			p = p->lchild;	
		}
		cout << p->data;
		while (p->rtag == Thread&&p->rchild!=T){
				p = p->rchild;
				cout << p->data;
		}
		p = p->rchild;  //指向头结点
	}
}

int main(){
	int level = 1;
	ThreadBiTree p,T = NULL;
	cout << "输入一颗二叉树（前序遍历方式）：" << endl;
	CreatBinaryTree(&T);//AB C  DE   |ABC  D  E F  |
	
	cout << "中序方法实现线索二叉树:\n";
	InOrderThread(&p,T); 
	cout << "中序输出二叉树\n";
	MidOutputBiTree(p);  //p是头指针，T是头结点
	cout << endl;

}