//程序实现采用顺序存储的循环队列
//2015/11/3
#include <iostream>
typedef int ElemType;
typedef int Status;
using namespace std;
#define MAXSIZE 400
#define OK 1
#define ERROR -1

//循环队列的结构体
typedef struct CycleQueue{
	ElemType* base;
	int front; //队头指针
	int rear; //队尾指针
}CycleQueue;

//循环队列的初始化
Status InitCycleQueue(CycleQueue* q){
	q->base = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));//动态申请空间
	if (!q->base){
		cout << "申请内存失败！" << endl;
		return ERROR; //申请空间失败
	}
	q->front = q->rear = 0;//初始指针指向0
}

//入队列操作
Status InsertCycleQueue(CycleQueue* q, ElemType e){
	if ((q->rear + 1) % MAXSIZE == q->front){
		cout <<  "队列已满！" << endl;//队列已满
		return ERROR;
	} 
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE; //队尾指针指向下一个位置
	return OK;
}

//出队列操作
Status DeleteCycleQueue(CycleQueue* q, ElemType* e){
	if (q->front == q->rear){
		cout << "队列为空！";
		return ERROR;
	}
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE; //更新队头指针
	return OK;
}


int main(){
	CycleQueue q;
	cout << "初始化循环队列" << endl;
	InitCycleQueue(&q);
	cout << "循环队列初始化结束！" << endl;
	ElemType data;
	cout << "输入队列（回车结束）：";
	while (cin >> data){
		InsertCycleQueue(&q, data);
		if (char c = cin.get() == '\n') break;
	}

	//输出队列
	ElemType e;
	cout << "输出该队列：" << endl;
	while (1){
		DeleteCycleQueue(&q, &e);
		cout << e <<" ";
		if (q.front == q.rear) break;
	}
	cout << endl;

	return 0;
}

