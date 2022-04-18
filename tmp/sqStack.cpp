#include <iostream>
typedef int ElemType;
typedef int Status;//操作状态指示
using namespace std;
#define OK 1
#define ERROE -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//栈的结构体
typedef struct sqStack{
	ElemType* base;//栈底指针
	ElemType* top; //栈顶指针
	int StackSize;//当前栈最大容量

}sqStack;

//栈的初始化
Status InitStack(sqStack* s){
	s->base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if (!s->base) exit(0);
	s->top = s->base;//初始化时都指向栈底
	s->StackSize = STACK_INIT_SIZE;
	return OK;
}

//入栈操作
Status StackPush(sqStack* s,ElemType e){
	//栈满则追加空间
	if (s->top - s->base >= s->StackSize){
		s->base = (ElemType*)realloc(s->base,s->StackSize+STACKINCREMENT*sizeof(ElemType));//增加容量
		if (!s->base) exit(0);
		s->top = s->base + s->StackSize;
		s->StackSize = s->StackSize + STACKINCREMENT; //更新栈的最大容量
	}
	*(s->top) = e;
	s->top++;
	return OK;
}

//出栈操作
Status StackPop(sqStack* s, ElemType *e){
	if (s->top == s->base) return ERROE;//空栈
	*e = *(--(s->top));
	return OK;
}

//清空一个栈
Status StackClear(sqStack* s){
	s->top = s->base;
	return OK;
}

//销毁一个栈
Status StackDestroy(sqStack* s){
	delete s->base;
	s->base = s->top = NULL;
	s->StackSize = 0;
	return OK;
}

//计算当前栈的容量
int StackLenghth(sqStack s){
	return s.top - s.base;
}
int main(){
	sqStack s;

	//对栈进行初始化
	InitStack(&s);
	
	//入栈操作
	StackPush(&s, 'H');
	StackPush(&s, 'E');
	StackPush(&s, 'E');
	
	//出栈操作
	int len = StackLenghth(s);
	cout << "当前栈容量：" << len << endl;
	cout << "输出该栈：\n";
	ElemType e;  
	for (int i = 0; i < len; ++i){
		StackPop(&s, &e);
		cout << e << endl;
	}
	//销毁一个栈
	StackDestroy(&s);
	return 0;
}
