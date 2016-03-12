//程序采用双向链表实现如下功能
//输入一个整数，使得26个字母的排序发生变化，如输入3
//输出: DEFGHIJKLMNOPQRSTUVWXYZABC,当输入-3
//输出: XYZABCDEFGHIJKLMNOPQRSTUVW

#include <iostream>
#define OK 1
#define ERROR 0
using namespace std;
typedef int ElemType;
typedef int Status; //操作结果指示

//双向链表数据结构
typedef struct DualNode{
	ElemType data;
	struct DualNode* prior;//前驱结点
	struct DualNode* next; //后继结点
}DualNode,*DualLinkList; //两个别名

Status InitDualLinkList(DualLinkList *L){
	DualNode *p, *q; //定义p、q两个指针交替赋值
	*L = (DualLinkList)malloc(sizeof(DualNode));
	if (!(*L)){
		return ERROR; //分配结点空间失败
	}
	(*L)->next = (*L)->prior = NULL; //初始化头结点
	p = (*L); // 初始化p

	for (int i = 0; i < 26; i++){
		q = (DualNode*)malloc(sizeof(DualNode));
		if (!q){
			return ERROR;
		}
		q->data = 'A' + i;
		q->prior = p; //q的前驱结点
		q->next = p->next;//q->next = NULL代码不灵活
		p->next = q;
		p = q;//p和q改变位置
	}
	p->next = (*L)->next; //构成一个循环
	(*L)->next->prior = p;

	return OK;
}

void AlphabetSort(DualLinkList* L, int i){
	if (i > 0){
		do{
			(*L) = (*L)->next;
		} while (--i);
	}
	if (i < 0){
		do{
			(*L) = (*L)->next;
		} while (++i);
	}
}
int main(){
	DualNode* L;
	int n;
	//初始化双向链表
	InitDualLinkList(&L); 

	cout << "请输入一个整数：";
	cin >> n;
	AlphabetSort(&L, n);
	for (int i = 0; i < 26; i++){
		L = L->next;
		cout << char(L->data);
	}
	cout << endl;
	return 0;

}
