#include <iostream>
#include <iomanip>
using namespace std;

#define NUM 10 //define the array length

int main(){
	int a[NUM] = {6,3,7,1,9,3,4,5,11,2};
	cout << "Before Sort:\n";
	for (int i =0;i < NUM;i++){
		cout << a[i] <<" ";
	}
	cout << "\n";
	
	//Bubble sort
	int  temp;
	cout << "After Bubble Sort:\n";
	for(int i = 0;i < NUM;++i){
		for(int j = NUM-1;j > i;j--){
			if(a[j-1]>a[j]){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j]  = temp;
			}
		}
	}
	//Input resluts
	for(int i = 0;i < NUM;++i){
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}
