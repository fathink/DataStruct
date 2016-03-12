//线性表的基本操作
#include <iostream>
#include <time.h>
#include <malloc.h>
#define ERROR -1
using namespace std;
typedef int ElemType;
typedef struct Node{
	ElemType data;       //数据域
	struct Node *next;   //指针域
}Node;
typedef struct Node *LinkList; //LinkList为指向Node的指针

//判断是否是空链表
int IsEmpty(LinkList L){
	return L->next == NULL;
}

//输出链表操作
int LinkListPrint(LinkList L){
	if (!L){ cout << "这是一个空链表" << endl; return -1; }
	while (L->next){
		cout << L->next->data << " ";
		L = L->next;
	}
	cout << endl;
	return 0;
}

//头插法生成链表
LinkList CreatListHead(LinkList L,int n){
	LinkList p;
	srand(time(0));//初始化随机数种子
 	L = (LinkList)malloc(sizeof(Node)); //创建头结点
	L->next = NULL;
	for (int i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node)); //临时Node
		//p->data = rand() % 100 + 1; //1~100随机数
		p->data = i + 1;
		p->next = L->next;
		L->next = p;//插到表头
	}
	return L;
}

//尾插法生成链表
LinkList CreatListTail(LinkList L, int n){
	LinkList p,r;//
	srand(time(0));
	L = (LinkList)malloc(sizeof(Node)); //创建头结点
	L->next = NULL;
	r = L;   //将头结点保存在r中
	for (int i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));//临时结点
		//p ->data = rand() % 100 + 1;
		p->data = i + 1;
		p->next = NULL;  //保证链表最后一个结点为空
		r->next = p;
		r = p;
	}
	return L;

}

//获取元素操作
ElemType GetElem(LinkList L, int i){
	if (!L){ cout << "这是一个空链表" << endl; return -1; }
	int j=1;//从链表的第一个数开始遍历
	LinkList p;
	p = L->next;//初始化遍历指针
	while (p&&j < i){
		p = p->next;//指针后移,找到第i个元素为止
		++j;
	}
	if (!p || j > i){ cerr << "ERROR"; return -1; } //到链表末端或者未找到
	ElemType e = p->data;
	return e;
}

//插入元素操作
LinkList LinkListInsert(LinkList L, int i,ElemType e){
	if (!L){ cerr << "ERROR"; return L; }
	int j = 1;//初始化遍历操作
	LinkList p, s; //初始化待插入结点的前后结点
	p = L;
	p = p->next;
	while (p&&j <i){
		p = p->next;
		++j;
	}
	if (!p || j > i){ cerr << "ERROR"; return L; }
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;//给新结点赋值
	s->next = p->next;
	p->next = s; 
	return L;
}

//删除元素操作
LinkList LinkListDelete(LinkList L, int i){
	int j = 1;
	LinkList p, q;
	p = L;//遍历L
	while (p->next&&j < i){
		p = p->next; //指针后移
		++j;
	}
	if (!(p->next) || j > i){ cerr << "ERROE"; return L; }
	q = p->next;     //待删除结点
	p->next = q->next; //删除结点
	delete q;
	return L;
}
int main(){
	
	int n = 10;//链表长度
	LinkList L0=0;

	//创建链表
	LinkList L=CreatListTail(L0, n);

	//输出链表
	LinkList Temp_L = L;
	cout << "输出链表：";
	LinkListPrint(Temp_L);

	//获取第i个元素
	ElemType e;
	int i = 2;
	e = GetElem(L, i);
	cout << "链表的第" << i << "个元素是: " << e << endl;

	////第i个位置插入元素
	//LinkList Insert_L=LinkListInsert(L, 10, 6);
	//cout << "输出插入新元素的链表：";
	//LinkListPrint(Insert_L);


	//第i个位置删除元素0
	LinkList Delete_L = LinkListDelete(L, 1);
	cout << "输出删除元素的链表：";
	LinkListPrint(Delete_L);

	return 0;

}