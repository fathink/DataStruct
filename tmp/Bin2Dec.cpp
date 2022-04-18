//�ó��򽫶�����תΪ10����
#include <iostream>
#include <math.h>
typedef char ElemType;
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

//��ʼ��ջ
Status InitStack(sqStack* s){
	s->base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if (!s->base) exit(0);
	s->top = s->base; //��ʼ����ָ��ջ��
	s->StackSize = STACK_INIT_SIZE;
	return OK;
}

//��ջ����
Status StackPush(sqStack* s,ElemType e){
	//ջ������ռ�
	if (s->top - s->base >= s->StackSize){
		s->base = (ElemType*)realloc(s->base, STACKINCREMENT*sizeof(ElemType));
		if (!s->base) exit(0);
	}
	*(s->top) = e;
	s->top++;
	return OK;
}

//��ջ����
Status StackPop(sqStack* s, ElemType* e){
	if (s->top == s->base) exit(0);//��ջ
	*e = *(--(s->top));
}

//��ǰջ����
int StackLength(sqStack s){
	return s.top - s.base;
}

int main(){
	ElemType data,e;
	int sum=0;
	sqStack s;
    //��ʼ��ջ
	InitStack(&s);
	cout << "�������������������س���������";
	while (char c = cin.get() != '\n'){
		cin.unget();
		cin >> e;
		StackPush(&s, e);
	}
	cin.clear(); //������뻺����
	int len = StackLength(s); //��ȡջ��ǰ����
	cout << "ջ�ĵ�ǰ����Ϊ" << len << endl;
	for (int i = 0; i < len; ++i){
		StackPop(&s, &e);
		sum = sum + (e - 48)*pow(2,i);
	}
	cout << "ת��Ϊʮ����Ϊ" << sum << endl;

	return 0;
}

