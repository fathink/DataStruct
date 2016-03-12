//����ʵ�ֶԶ���(��ʽ�洢)�����ɲ���
//2015/11
#include <iostream>
typedef int ElemType;
typedef int Status;
using namespace std
#define OK 1
#define ERROR -1

//���еĽṹ��
typedef struct QNode{
	ElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front, rear;//��ͷ��βָ��
}LinkQueue;

//���еĳ�ʼ��
Status InitQueue(LinkQueue* q){
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	//q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front) exit(0);
	q->front->next = NULL; //ͷ���ָ��NULL
	return OK;
}

//��ӵĲ���
Status QueueInsert(LinkQueue* q, ElemType e){
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p; //���������ӵ���Ԫ��
	q->rear = p;      //����βָ��ָ�����һ��Ԫ��
	return OK;
}

//���ӵĲ���
Status QueueDelete(LinkQueue* q, ElemType* e){
	QueuePtr p;
	if (q->front == q->rear) return ERROR;//�ն���
	p = q->front->next; //������Ԫ��
	*e = p->data; //������Ԫ�ص�ֵ
	q->front->next = p->next; //���ӵ���һ��Ԫ��
	if (q->rear == p)
		q->rear = q->front;//ֻ��һ��Ԫ��ʱ�Ĵ���
}

//����һ������
Status QueueDestroy(LinkQueue* q){
	while (q->front){
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
	return OK;
}

//�������
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
	cout << "��ʼ�����У�" << endl;
	InitQueue(&q);
	cout << "������У��س���������";
	while (cin>>data){
		QueueInsert(&q, data);
		if (char c = cin.get() == '\n') break;
	}
	cout << "������У�\n";
	QueuePrint(q);

	QueueDestroy(&q);
	
	return 0;
}
