//该程序将二进制转为10进制
#include <iostream>
#include <math.h>
typedef char ElemType;
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

//初始化栈
Status InitStack(sqStack* s){
	s->base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if (!s->base) exit(0);
	s->top = s->base; //初始化都指向栈底
	s->StackSize = STACK_INIT_SIZE;
	return OK;
}

//入栈操作
Status StackPush(sqStack* s,ElemType e){
	//栈满扩大空间
	if (s->top - s->base >= s->StackSize){
		s->base = (ElemType*)realloc(s->base, STACKINCREMENT*sizeof(ElemType));
		if (!s->base) exit(0);
	}
	*(s->top) = e;
	s->top++;
	return OK;
}

//出栈操作
Status StackPop(sqStack* s, ElemType* e){
	if (s->top == s->base) exit(0);//空栈
	*e = *(--(s->top));
}

//当前栈长度
int StackLength(sqStack s){
	return s.top - s.base;
}

int main(){
	ElemType data,e;
	int sum=0;
	sqStack s;
    //初始化栈
	InitStack(&s);
	cout << "请输出二进制数（输入回车结束）：";
	while (char c = cin.get() != '\n'){
		cin.unget();
		cin >> e;
		StackPush(&s, e);
	}
	cin.clear(); //清除输入缓冲区
	int len = StackLength(s); //获取栈当前容量
	cout << "栈的当前容量为" << len << endl;
	for (int i = 0; i < len; ++i){
		StackPop(&s, &e);
		sum = sum + (e - 48)*pow(2,i);
	}
	cout << "转换为十进制为" << sum << endl;

	return 0;
}

