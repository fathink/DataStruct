#include <iostream>
using namespace std;

typedef char ElemType;
typedef enum { Link, Thread }PointerNag;//����״̬����


//����һ�����������
typedef struct ThreadBiTNode{
	ElemType data;
	ThreadBiTNode *lchild, *rchild;
	PointerNag ltag;
	PointerNag rtag;
}ThreadBiTNode, *ThreadBiTree;

ThreadBiTree pre; //pre��һ��ȫ�ֱ���
//��ʼ����,����ǰ�������ʽ����
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

//�������������
void MidOrderTraverse(ThreadBiTree T){
	if (T){
		MidOrderTraverse(T->lchild); //����
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
		MidOrderTraverse(T->rchild); //�ҽڵ�
	}
}

//���������������ʼ����
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




//����������������ǵݹ���ʽ��
void MidOutputBiTree(ThreadBiTree T){
	ThreadBiTree p;
	p = T->lchild;
	while (p!= T){   //�������߱�������ʱ
		while (p->ltag == Link){
			p = p->lchild;	
		}
		cout << p->data;
		while (p->rtag == Thread&&p->rchild!=T){
				p = p->rchild;
				cout << p->data;
		}
		p = p->rchild;  //ָ��ͷ���
	}
}

int main(){
	int level = 1;
	ThreadBiTree p,T = NULL;
	cout << "����һ�Ŷ�������ǰ�������ʽ����" << endl;
	CreatBinaryTree(&T);//AB C  DE   |ABC  D  E F  |
	
	cout << "���򷽷�ʵ������������:\n";
	InOrderThread(&p,T); 
	cout << "�������������\n";
	MidOutputBiTree(p);  //p��ͷָ�룬T��ͷ���
	cout << endl;

}