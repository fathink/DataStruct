//ŷ������㷨�����������
#include <iostream>
using namespace std;
int main(){
	unsigned int M, N, Rem;
	cout << "Please input two numbers:" << endl;
	cin >> M >> N;
	while (N > 0)
	{
		Rem = M%N;
		M = N;
		N = Rem;
	}
	cout << "The greatest common factor is: \n" << M << endl;
	
}