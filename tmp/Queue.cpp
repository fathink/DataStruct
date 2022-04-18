//程序实现对队列(链式存储)的若干操作
//2015/11
#include <iostream>
typedef int ElemType;
typedef int Status;
using namespace std
#define OK 1
#define ERROR -1

//队列的结构体
typedef struct QNode{
	ElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front, rear;//队头和尾指针
}LinkQueue;

//队列的初始化
Status InitQueue(LinkQueue* q){
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	//q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front) exit(0);
	q->front->next = NULL; //头结点指向NULL
	return OK;
}

//入队的操作
Status QueueInsert(LinkQueue* q, ElemType e){
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p; //将队列链接到新元素
	q->rear = p;      //将队尾指针指向最后一个元素
	return OK;
}

//出队的操作
Status QueueDelete(LinkQueue* q, ElemType* e){
	QueuePtr p;
	if (q->front == q->rear) return ERROR;//空队列
	p = q->front->next; //待出队元素
	*e = p->data; //待出队元素的值
	q->front->next = p->next; //连接到下一个元素
	if (q->rear == p)
		q->rear = q->front;//只有一个元素时的处理
}

//销毁一个队列
Status QueueDestroy(LinkQueue* q){
	while (q->front){
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
	return OK;
}

//输出队列
Status QueuePrint(LinkQueue q){
	QueuePtr p;
	p = q.front->next;
	while (p){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return OK;
}

int main(){
	LinkQueue q;
	ElemType e,data;
	cout << "初始化队列：" << endl;
	InitQueue(&q);
	cout << "输入队列（回车结束）：";
	while (cin>>data){
		QueueInsert(&q, data);
		if (char c = cin.get() == '\n') break;
	}
	cout << "输出队列：\n";
	QueuePrint(q);

	QueueDestroy(&q);
	
	return 0;
}
