//本程序实现冒泡排序的简单样例
//2015/9/17
#include <iostream>
#include <vector>
using namespace std;
int main(){
	float temp;
	vector<float> vec; //{1,5,7,4,5,6}
	cout << "Please input the array to be sorted:" << endl;
	while (cin >> temp){
		vec.push_back(temp);
		if (getchar() == '\n') break;
	}
	//Sorting
	for (int i = 0; i != vec.size()-1; ++i)
		for (int j = 0; j != vec.size() - i-1; ++j){
			if (vec[j] > vec[j + 1]) swap(vec[j], vec[j + 1]);//exchange the number
		}


	return 0;
}