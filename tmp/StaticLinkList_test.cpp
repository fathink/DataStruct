#include <iostream>
using namespace std;
typedef char ElemType;
#define MAXSIZE 100
#define OK  1
#define ERROR -1
typedef struct SNode{
	ElemType data;   //数据
	int cur;        //游标
}SNode;
typedef struct SNode StaticLinkList[MAXSIZE];


//静态链表初始化
bool InitStaticLinkList(StaticLinkList &L){
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		L[i].cur = i + 1;
	L[MAXSIZE-1].cur = 0; //最后一个指针域指向
	return OK;
}

//打印静态链表
bool StaticLinkListPrint(StaticLinkList &L){
	int i = L[MAXSIZE - 1].cur;
	while (i != 0){
		cout << L[i].data << " ";
		i = L[i].cur;
	}
	cout << endl;
	return OK;

}
//计算SLL中元素的个数
int length_SLL(StaticLinkList L){
	int j = 0;
	int i = L[MAXSIZE - 1].cur;//第一个元素下标
	while (i){
		i = L[i].cur;
		++j;
	}
	return j;
}
//申请分配一个空闲结点
int malloc_SLL(StaticLinkList L){
	int i = L[0].cur;//取头结点之后的一个空闲结点做分配
	if (L[0].cur)
		L[0].cur = L[i].cur;//更新第一个结点的游标，指向第一个未存放数据的下标
	return i; //返回第一个未存放元素的下标
}

//释放一个空闲结点,结点的下标为i
void free_SLL(StaticLinkList L,int i){
	L[i].cur = L[0].cur;//将回收的结点放在头结点之后
	L[0].cur = i;

}

//静态链表L插入元素,i结点插入
bool StaticLinkListInsert(StaticLinkList &L,int i,ElemType e){
	int j, k, l;
	k = MAXSIZE - 1;//数组最后一个元素下标
	if (i<1 || i>length_SLL(L) + 1){
		cout << "输入错误，当前链表长度为" << length_SLL(L)
			<< ",输入范围为1 ~ " << length_SLL(L) + 1 <<endl;
		return -1; }
	j = malloc_SLL(L); //获取未存放元素的下标分量
	if (j){
		L[j].data = e;
		for (l = 1; l <= i - 1; l++){  //遍历链表，找到游标为0的下标
			k = L[k].cur;
		}
		L[j].cur = L[k].cur; //更新最后一个元素的游标，最后一个元素的游标必须为0
		L[k].cur = j;        //更新第一个游标的值，指向第一个未存放值的下标
		return OK;
	}
	return ERROR;
}

//静态链表删除i元素
bool StaticLinkListDelete(StaticLinkList &L, int i){
	int j, k;
	if (i < 1 || i>length_SLL(L)){ 
		cout << "输入错误，当前链表长度为 " << length_SLL(L)
			<< ",输入范围为1 ~ " << length_SLL(L) << endl;
		return ERROR; }
	k = MAXSIZE - 1; //数组最后一个元素下标
	for (j = 1; j <= i - 1; j++)
		k = L[k].cur; //遍历链表，找到待删除结点前一个结点的下标
	j = L[k].cur;     //待删除结点的下标
	L[k].cur = L[j].cur; //删除结点
	free_SLL(L, j);
	return OK;
}


int main(){
	StaticLinkList L;

	//初始化静态链表
	InitStaticLinkList(L);
	
	//插入元素
	StaticLinkListInsert(L, 1, 'a');
	StaticLinkListInsert(L, 2, 'c');
	StaticLinkListInsert(L, 3, 'd');
	StaticLinkListInsert(L, 2, 'b');
	StaticLinkListInsert(L, 5, 'f');

	//打印静态链表
	cout << "输出链表：" ;
	StaticLinkListPrint(L);

	//插入链表
	int i; ElemType data;
	cout << "请输入插入位置和插入元素：";
	cin >> i >> data;
	StaticLinkListInsert(L, i, data);
	cout << "输出插入元素后的链表：";
	StaticLinkListPrint(L);

	//删除静态链表（第i个元素）
	cout << "请输入删除元素下标：";
	cin >> i ;
	StaticLinkListDelete(L, i);
	cout << "输出删除元素后的链表：";
	StaticLinkListPrint(L);
	   
	//cout << length_SLL(L);

	return 0;
}