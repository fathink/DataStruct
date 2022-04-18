#include <iostream>
using namespace std;

void up_and_down(int n){
	cout << "Level_" << n << ":n location " << &n <<endl;
	if (n < 4)
		up_and_down(n + 1);
	cout << "Level_" << n << ":n location " << &n << endl;
}

//µ¹ÐòÊä³ö×Ö·û´®
void print(){
	char a;
	//cout << "ÇëÊäÈë×Ö·û´®£¨#½áÊøÊäÈë£©£º";
	cin >> a;
	if (a != '#') print();
	if (a != '#') cout << a << " "; //²»Êä³ö#
	
}

//ì³²¨ÄÇÆõÊýÁÐµÝ¹éÊµÏÖ
int Fib(int n){ 
	if (n < 2) return n == 0 ? 0 : 1;
	return Fib(n - 1) + Fib(n - 2);
}

//ÊýµÄ½×³ËµÝ¹éÊµÏÖ
int factorial(int n){
	if (n == 0) return 1;
	else{
		return n*factorial(n - 1);
	}
}
int main(){

	up_and_down(1);


	//cout << "ÇëÇëÊäÈë×Ö·û´®£¨#½áÊøÊäÈë£©£º";
	//print();
	//cout << endl;

	//int n = 5;
	//int sum = factorial(n);
	//cout << sum << endl;
	return 0;
}