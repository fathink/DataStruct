#include <iostream>
typedef int ElemType;
typedef int Status;//����״ָ̬ʾ
using namespace std;
#define OK 1
#define ERROE -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//ջ�Ľṹ��
typedef struct sqStack{
	ElemType* base;//ջ��ָ��
	ElemType* top; //ջ��ָ��
	int StackSize;//��ǰջ�������

}sqStack;

//ջ�ĳ�ʼ��
Status InitStack(sqStack* s){
	s->base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if (!s->base) exit(0);
	s->top = s->base;//��ʼ��ʱ��ָ��ջ��
	s->StackSize = STACK_INIT_SIZE;
	return OK;
}

//��ջ����
Status StackPush(sqStack* s,ElemType e){
	//ջ����׷�ӿռ�
	if (s->top - s->base >= s->StackSize){
		s->base = (ElemType*)realloc(s->base,s->StackSize+STACKINCREMENT*sizeof(ElemType));//��������
		if (!s->base) exit(0);
		s->top = s->base + s->StackSize;
		s->StackSize = s->StackSize + STACKINCREMENT; //����ջ���������
	}
	*(s->top) = e;
	s->top++;
	return OK;
}

//��ջ����
Status StackPop(sqStack* s, ElemType *e){
	if (s->top == s->base) return ERROE;//��ջ
	*e = *(--(s->top));
	return OK;
}

//���һ��ջ
Status StackClear(sqStack* s){
	s->top = s->base;
	return OK;
}

//����һ��ջ
Status StackDestroy(sqStack* s){
	delete s->base;
	s->base = s->top = NULL;
	s->StackSize = 0;
	return OK;
}

//���㵱ǰջ������
int StackLenghth(sqStack s){
	return s.top - s.base;
}
int main(){
	sqStack s;

	//��ջ���г�ʼ��
	InitStack(&s);
	
	//��ջ����
	StackPush(&s, 'H');
	StackPush(&s, 'E');
	StackPush(&s, 'E');
	
	//��ջ����
	int len = StackLenghth(s);
	cout << "��ǰջ������" << len << endl;
	cout << "�����ջ��\n";
	ElemType e;  
	for (int i = 0; i < len; ++i){
		StackPop(&s, &e);
		cout << e << endl;
	}
	//����һ��ջ
	StackDestroy(&s);
	return 0;
}
