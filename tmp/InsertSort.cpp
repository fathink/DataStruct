#include <iostream>
#include <iomanip>
using namespace std;
void InsertSort(int a[],int n);
 
int main(){
	int a[6] = {3,7,5,1,4,2};
	cout << "Begfor Sort:\n";
	for(int i = 0;i < 6;++i){
		cout << a[i] <<" "; 
	}
	cout << "\n";
	cout << "After Insert sort:\n";
	InsertSort(a,6); 
	for(int i = 0;i < 6;++i){
		cout << a[i] <<" ";  
	}
	return 0;
}

void InsertSort(int a[],int n){
	int i,j,temp;
	for(i = 1;i < n;++i){
		if(a[i] < a[i-1]){
			temp = a[i];
			for(j = i -1;a[j] > temp && j>=0;j--){
				a[j+1] = a[j];
			}
			a[j+1] = temp;
		}
	
	}
}
