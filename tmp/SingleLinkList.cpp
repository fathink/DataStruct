//���Ա�Ļ�������
#include <iostream>
#include <time.h>
#include <malloc.h>
#define ERROR -1
using namespace std;
typedef int ElemType;
typedef struct Node{
	ElemType data;       //������
	struct Node *next;   //ָ����
}Node;
typedef struct Node *LinkList; //LinkListΪָ��Node��ָ��

//�ж��Ƿ��ǿ�����
int IsEmpty(LinkList L){
	return L->next == NULL;
}

//����������
int LinkListPrint(LinkList L){
	if (!L){ cout << "����һ��������" << endl; return -1; }
	while (L->next){
		cout << L->next->data << " ";
		L = L->next;
	}
	cout << endl;
	return 0;
}

//ͷ�巨��������
LinkList CreatListHead(LinkList L,int n){
	LinkList p;
	srand(time(0));//��ʼ�����������
 	L = (LinkList)malloc(sizeof(Node)); //����ͷ���
	L->next = NULL;
	for (int i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node)); //��ʱNode
		//p->data = rand() % 100 + 1; //1~100�����
		p->data = i + 1;
		p->next = L->next;
		L->next = p;//�嵽��ͷ
	}
	return L;
}

//β�巨��������
LinkList CreatListTail(LinkList L, int n){
	LinkList p,r;//
	srand(time(0));
	L = (LinkList)malloc(sizeof(Node)); //����ͷ���
	L->next = NULL;
	r = L;   //��ͷ��㱣����r��
	for (int i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));//��ʱ���
		//p ->data = rand() % 100 + 1;
		p->data = i + 1;
		p->next = NULL;  //��֤�������һ�����Ϊ��
		r->next = p;
		r = p;
	}
	return L;

}

//��ȡԪ�ز���
ElemType GetElem(LinkList L, int i){
	if (!L){ cout << "����һ��������" << endl; return -1; }
	int j=1;//������ĵ�һ������ʼ����
	LinkList p;
	p = L->next;//��ʼ������ָ��
	while (p&&j < i){
		p = p->next;//ָ�����,�ҵ���i��Ԫ��Ϊֹ
		++j;
	}
	if (!p || j > i){ cerr << "ERROR"; return -1; } //������ĩ�˻���δ�ҵ�
	ElemType e = p->data;
	return e;
}

//����Ԫ�ز���
LinkList LinkListInsert(LinkList L, int i,ElemType e){
	if (!L){ cerr << "ERROR"; return L; }
	int j = 1;//��ʼ����������
	LinkList p, s; //��ʼ�����������ǰ����
	p = L;
	p = p->next;
	while (p&&j <i){
		p = p->next;
		++j;
	}
	if (!p || j > i){ cerr << "ERROR"; return L; }
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;//���½�㸳ֵ
	s->next = p->next;
	p->next = s; 
	return L;
}

//ɾ��Ԫ�ز���
LinkList LinkListDelete(LinkList L, int i){
	int j = 1;
	LinkList p, q;
	p = L;//����L
	while (p->next&&j < i){
		p = p->next; //ָ�����
		++j;
	}
	if (!(p->next) || j > i){ cerr << "ERROE"; return L; }
	q = p->next;     //��ɾ�����
	p->next = q->next; //ɾ�����
	delete q;
	return L;
}
int main(){
	
	int n = 10;//������
	LinkList L0=0;

	//��������
	LinkList L=CreatListTail(L0, n);

	//�������
	LinkList Temp_L = L;
	cout << "�������";
	LinkListPrint(Temp_L);

	//��ȡ��i��Ԫ��
	ElemType e;
	int i = 2;
	e = GetElem(L, i);
	cout << "����ĵ�" << i << "��Ԫ����: " << e << endl;

	////��i��λ�ò���Ԫ��
	//LinkList Insert_L=LinkListInsert(L, 10, 6);
	//cout << "���������Ԫ�ص�����";
	//LinkListPrint(Insert_L);


	//��i��λ��ɾ��Ԫ��0
	LinkList Delete_L = LinkListDelete(L, 1);
	cout << "���ɾ��Ԫ�ص�����";
	LinkListPrint(Delete_L);

	return 0;

}