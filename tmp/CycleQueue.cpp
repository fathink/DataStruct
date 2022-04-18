//����ʵ�ֲ���˳��洢��ѭ������
//2015/11/3
#include <iostream>
typedef int ElemType;
typedef int Status;
using namespace std;
#define MAXSIZE 400
#define OK 1
#define ERROR -1

//ѭ�����еĽṹ��
typedef struct CycleQueue{
	ElemType* base;
	int front; //��ͷָ��
	int rear; //��βָ��
}CycleQueue;

//ѭ�����еĳ�ʼ��
Status InitCycleQueue(CycleQueue* q){
	q->base = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));//��̬����ռ�
	if (!q->base){
		cout << "�����ڴ�ʧ�ܣ�" << endl;
		return ERROR; //����ռ�ʧ��
	}
	q->front = q->rear = 0;//��ʼָ��ָ��0
}

//����в���
Status InsertCycleQueue(CycleQueue* q, ElemType e){
	if ((q->rear + 1) % MAXSIZE == q->front){
		cout <<  "����������" << endl;//��������
		return ERROR;
	} 
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE; //��βָ��ָ����һ��λ��
	return OK;
}

//�����в���
Status DeleteCycleQueue(CycleQueue* q, ElemType* e){
	if (q->front == q->rear){
		cout << "����Ϊ�գ�";
		return ERROR;
	}
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE; //���¶�ͷָ��
	return OK;
}


int main(){
	CycleQueue q;
	cout << "��ʼ��ѭ������" << endl;
	InitCycleQueue(&q);
	cout << "ѭ�����г�ʼ��������" << endl;
	ElemType data;
	cout << "������У��س���������";
	while (cin >> data){
		InsertCycleQueue(&q, data);
		if (char c = cin.get() == '\n') break;
	}

	//�������
	ElemType e;
	cout << "����ö��У�" << endl;
	while (1){
		DeleteCycleQueue(&q, &e);
		cout << e <<" ";
		if (q.front == q.rear) break;
	}
	cout << endl;

	return 0;
}

