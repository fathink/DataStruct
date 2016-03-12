//********************************
//程序实现折半查找方式进行查找数据
//2015/11
//********************************
#include <iostream>
using namespace std;
#define N 45

//构造斐波那契数列
int Fib(int n){
	if (n < 2) return n == 0 ? 0 : 1;
	return Fib(n - 1) + Fib(n - 2);
}

//折半查找（迭代）
int bin_search_iteration(int str[], int n,int key){
	int low, high, mid;

	low = 0; high = n - 1;//初始化高低指针
	while (low <= high){
		mid = (low + high) / 2;
		if (str[mid] == key) return mid;
		if (str[mid] < key)	low = mid + 1;
		if (str[mid] > key)	high = mid - 1;
	}
}
int mid;
//迭代查找(递归）
int bin_search_recursive(int str[], int low, int high,int key){
	
	int temp;
	
	if (low > high){
		cout << "查找失败！" << endl;
		return -1;
	} 
	else {
		mid = (low + high) / 2;
		if (str[mid] == key) return mid;
		if (str[mid] < key) {
			return  bin_search_recursive(str, mid + 1, high, key); //数组的后半部分查找 
		}
		else
			 return bin_search_recursive(str, low, mid-1, key); //数组的前半部分查找
	}
}
int main(){
	int str[N] = {}; //构造一个斐波那契数组
	str[0] = 0;
	str[1] = 1;
	for (int i = 2; i < N; ++i){
		str[i] = str[i-1] + str[i-2];
	}
	int t = bin_search_recursive(str,0,N-1,3);
	cout << t << endl;
	return 0;
}