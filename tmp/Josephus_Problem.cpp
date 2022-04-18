//约瑟夫问题的编程实现

#include <iostream>
#include <iomanip>
using namespace std;
typedef int ElemType;

//定义循环体结构
typedef struct CirLinkList{
	ElemType data;
	struct CirLinkList* next;
}node;

//初始化循环链表
void CirLinkListInit(node** pNode,int count){
	ElemType item;
	//int count;
	node* temp;
	node* target;
	while (1){
		//cin >> count;
		for (int i = 1; i <= count; i++){
			item = i;
			//fflush(stdin); //清除缓冲区
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
		}
		if (item == count) {
			cout << "初始化结束！" << endl;
			return;//输入0结束初始化
		}
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

//打印循环链表
int CirLinkListPrint(node* L){
	node* temp;
	int count = 0;
	for (temp = L; temp->next != L; temp = temp->next){
		cout << left <<setw(2) <<temp->data << " ";
		count++;
		if (count%10==0) cout << endl;
	}
	cout << left <<setw(2) << temp->data << endl; //输出最后一个元素
	
	return 0;
}


int main(){
	node* L = 0;
	int num = 3; //相隔3
	int count;   //总人数
	//初始化循环链表
	cout << "请输入人数：";
	//cin >> count;
	count = 12;
	CirLinkListInit(&L,count);
	cout << "输出链表：\n";
	CirLinkListPrint(L);

	cout << "输出结果如下：" << endl;
	node* temp = L;
	while (1){
		cout << "选择第" <<right<<setw(2)<< temp->next->next->data << "个人" << endl;
		CirLinkListDelete(&temp, num);
		--count;
		if (count == 2) break;
		temp = temp->next->next;
	}

	cout << "剩余人数" << temp->data << " " << temp->next->data << endl;



	return 0;

}