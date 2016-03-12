//该程序为桶排序的简单示例
//2015/9/17
#include <iostream>
#include <vector>
using namespace std;
#define MAXSIZE 100
template <class T> 
int getArrayLen(T& array){
	return sizeof(array) / sizeof(array[0]);
}

int main(){
	int array[MAXSIZE] = {0};
	vector<int> vec;
	cout << "Pleasw input the int array(0~100): " << endl;
	int temp;
	while (cin >> temp){
		vec.push_back(temp);
		if (getchar() == '\n') break;
	}

	//collect times
	for (auto it = vec.begin(); it != vec.end(); ++it)
		array[*it]++;
    
	//Input array
	cout << "The sorted array is :" << endl;
	for (int i = 0; i < MAXSIZE; ++i)
		if (array[i] != 0)
			for (int j = 0; j < array[i]; ++j)
				cout << i << " ";

	
}