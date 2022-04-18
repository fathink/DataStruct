//循环链表的相关操作
//fazuo 2015/10/24
#include <iostream>
using namespace std;
typedef int ElemType;

//定义循环链表结构体
typedef struct CirLinkList{
	ElemType data; //数据域
	struct CirLinkList* next; //指针域
}node; //node是CirLinkList的别名

//初始化循环链表
void CirLinkListInit(node** pNode){
	ElemType item, count = 1;
	node* temp; 
	node* target;
	while (1){
		cout << "输入第" << count << "结点的值，输入0结束初始化：";
		cin >> item;
		
		//for (int i = 8; i >= 0; i--){
		//	item = i;

			fflush(stdin); //清除缓冲区
			if (item == 0) {
				cout << "初始化结束！" << endl;
				return;//输入0结束初始化
			}
			if ((*pNode) == NULL){  //循环链表中只有一个结点
				*pNode = (node*)malloc(sizeof(struct CirLinkList));
				if (!(*pNode)) exit(0);
				(*pNode)->data = item;
				(*pNode)->next = *pNode; //首位相连
			}
			else{
				for (target = *pNode; target->next != *pNode; target = target->next)
					;//target指向最后一个结点
				temp = (node*)malloc(sizeof(struct CirLinkList)); //生成新结点
				if (!temp) exit(0);
				temp->data = item;
				temp->next = *pNode; //指向头结点
				target->next = temp;//链接上一个结点
			}


		//}

		++count; //结点数增1
	}
	return;
}

//循环链表第i个位置插入元素
//item是待插入元素，i是插入的位置
void CirLinkListInsert(node** pNode, ElemType item, int i){
	node *temp;
	node *target;
	if (i ==1){//第一个位置插入元素
		temp = (node*)malloc(sizeof(struct CirLinkList));//给临时节点分配空间
		if (!temp) exit(0);  //分配失败，退出函数
		temp->data = item;
		for (target = *pNode; target->next != *pNode; target = target->next)
			;//target为指向最后一个结点的指针
		temp->next = *pNode;
		target->next = temp;
		*pNode = temp;//*pNode指向头结点
	}
	else{
		target = *pNode;
		for (int j = 1; j < i - 1; ++j){
			target = target->next;   //指向第i-1个结点
		}
		temp = (node*)malloc(sizeof(struct CirLinkList));
		if (!temp) exit(0); //分配失败，退出函数
		temp->data = item;
		node* p = target->next; 
		target->next = temp;
		temp->next = p; 
	}
	return;
}

//循环链表第i个位置删除链表
void CirLinkListDelete(node** pNode, int i){
	node* temp;
	node* target; //初始化指向最后一个结点的指针
	if (i == 1){
		for (target = *pNode; target->next != *pNode; target = target->next)
			;//target指向最后一个结点的指针
		temp = *pNode;
		*pNode = (*pNode)->next; //删除第一个结点
		target->next = *pNode;  //尾结点指向第一个结点
		free(temp); 
	}
	else{
		target = *pNode;
		for (int j = 1; j < i - 1; ++j){
			target = target->next;    //指向第i-1个结点
		}
		temp = target->next;
		target->next = temp->next; //删除i结点
		free(temp);
	}
}

//查找操作，查找元素，返回该元素所在的位置
int CirLinkListSearch(node* pNode, ElemType e){
	int i = 1;
	node* target;
	for (target = pNode; target->data != e || target->next == pNode; ++i){
		target = target->next;
	}
	if (target->next == pNode) {
		cout << "表中不存在该元素！" << endl;
		return 0;
	}
	else return i;
}

//打印循环链表
int CirLinkListPrint(node* L){
	node* temp;
	for (temp = L; temp->next != L; temp = temp->next)
		cout << temp->data << " ";
	cout << temp->data << endl; //输出最后一个元素
	return 0;
}


int main(){
	int idx; //操作的索引
	ElemType e; int i,pos; 
	node* L = NULL; //将循环链表初始化为null
	cout << "============================================" << endl;
	cout << "1.链表初始化，2.链表插入元素，3.链表删除元素" << endl;
	cout << "4.链表查找操作，0.结束操作" << endl;
	cout << "============================================" << endl;
	cout << "请输入待操作的序号：";
	while (1){
		//cin.unget();
		cin >> idx;
		switch (idx){
		case 1:
			CirLinkListInit(&L);
			cout << "输出初始化的循环链表：" << endl;
			CirLinkListPrint(L);
			cout << endl;
			break;
		case 2:
			cout << "输入待插入结点数值和位置：";
			cin >> e >> i;
			CirLinkListInsert(&L, e, i);
			cout << "输出新链表：\n";
			CirLinkListPrint(L);
			cout << endl;
			break;
		case 3:
			cout << "输入待删除结点的位置：";
			cin >> i;
			CirLinkListDelete(&L,i);
			cout << "输出新链表：\n";
			CirLinkListPrint(L);
			cout << endl;
			break;
		case 4:
			cout << "输入待查找元素的值：";
            cin >> e;
		    pos = CirLinkListSearch(L, e);
		    cout << "元素值为" << e << "的索引为" << pos << "\n";
		    cout << endl;
		    break;
		default:
			break;
		}
		
		if (idx == 0){
			cout << "操作结束！\n"<<endl;
			break;
		}
		else{
			cout << "请输入待操作的序号：";
		}
		
	}

	////初始化循环链表
	//CirLinkListInit(&L);
	//
	////输出循环链表S
	//cout << "输出循环链表：\n";
	//CirLinkListPrint(L);

	////第i个位置插入结点
	//CirLinkListInsert(&L, 5, 1);
	//cout << "输出循环链表：\n";
	//CirLinkListPrint(L);
	//
	////第i个位置删除结点
	//CirLinkListDelete(&L, 4);
	//cout << "输出循环链表：\n";
	//CirLinkListPrint(L);

	////查找元素
	//int i = 5;
	//int pos=CirLinkListSearch(L, i);
	//cout << "元素值为"<<i<<"的索引为"<<pos<<"\n";
	//
	return 0;
}