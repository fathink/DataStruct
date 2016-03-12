#include <iostream>
using namespace std;

//将n盘子从x上借助y移动到z上
void hanoi(int n, char a, char b, char c){
	if (n == 1){
		cout << a << "->" << c <<endl;
	 }
	else
	{
		hanoi(n - 1, a, c, b);//将n-1个盘子从x借助z移动到y上
		cout << a << "->" << c << endl;//将第n个盘子从x移动到z上
		hanoi(n - 1, b, a, c);//将n-1个盘子从y借助x移动到z
	}
}
int main(){
	int n = 3;
 	hanoi(n, 'A', 'B', 'C');
	return 0;
}