#include <iostream>
using namespace std;

void up_and_down(int n){
	cout << "Level_" << n << ":n location " << &n <<endl;
	if (n < 4)
		up_and_down(n + 1);
	cout << "Level_" << n << ":n location " << &n << endl;
}

//��������ַ���
void print(){
	char a;
	//cout << "�������ַ�����#�������룩��";
	cin >> a;
	if (a != '#') print();
	if (a != '#') cout << a << " "; //�����#
	
}

//쳲��������еݹ�ʵ��
int Fib(int n){ 
	if (n < 2) return n == 0 ? 0 : 1;
	return Fib(n - 1) + Fib(n - 2);
}

//���Ľ׳˵ݹ�ʵ��
int factorial(int n){
	if (n == 0) return 1;
	else{
		return n*factorial(n - 1);
	}
}
int main(){

	up_and_down(1);


	//cout << "���������ַ�����#�������룩��";
	//print();
	//cout << endl;

	//int n = 5;
	//int sum = factorial(n);
	//cout << sum << endl;
	return 0;
}