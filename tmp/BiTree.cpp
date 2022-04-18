#include <iostream>
typedef char ElemType;
using namespace std;

//����һ�����������
typedef struct BiTNode{
	ElemType data;
	BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//��ʼ����,����ǰ�������ʽ����
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

//ǰ�����
void PreOrderTraverse(BiTree T, int level){
	if (T){
		cout << T->data << " level is " << level << endl;
		PreOrderTraverse(T->lchild, level+1);
		PreOrderTraverse(T->rchild, level+1);
	}
}

//�������
void MidOrderTraverse(BiTree T, int level){
	if (T){
		MidOrderTraverse(T->lchild, level + 1); //����
		cout << T->data << " level is " << level << endl;
		MidOrderTraverse(T->rchild, level + 1); //�ҽڵ�
	}
}

//�������
void ReaOrderTraverse(BiTree T, int level){
	if (T){
		ReaOrderTraverse(T->lchild, level + 1); //����
		ReaOrderTraverse(T->rchild, level + 1); //�ҽڵ�
		cout << T->data << " level is " << level << endl;
	}
}
int main(){
	int level = 1;
	BiTree T = NULL;
	cout << "����һ�Ŷ�������ǰ�������ʽ����"<<endl;
 	CreatBinaryTree(&T);//AB C  DE   |
	cout << "ǰ�����������:\n";
	PreOrderTraverse(T, level);
	cout << "�������������:\n";
	MidOrderTraverse(T, level);
	cout << "�������������:\n";
	ReaOrderTraverse(T, level);

}

