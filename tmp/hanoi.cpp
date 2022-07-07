#include <iostream>
using namespace std;

//��n���Ӵ�x�Ͻ���y�ƶ���z��
void hanoi(int n, char a, char b, char c){
	if (n == 1){
		cout << a << "->" << c <<endl;
	 }
	else
	{
		hanoi(n - 1, a, c, b);//��n-1�����Ӵ�x����z�ƶ���y��
		cout << a << "->" << c << endl;//����n�����Ӵ�x�ƶ���z��
		hanoi(n - 1, b, a, c);//��n-1�����Ӵ�y����x�ƶ���z
	}
}
int main(){
	int n = 3;
 	hanoi(n, 'A', 'B', 'C');
	return 0;
}