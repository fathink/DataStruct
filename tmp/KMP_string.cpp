//����ʵ��BF�㷨�����ص�ģʽƥ���㷨
//              : KMP�㷨
//2015/11/5
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#define N 100

int BFMatch(string* s, string* t, int* index);
int BFmatch2(const string& target, const string& pattern);
int* getNext(const string& pattern);//KMP�㷨next��������
int KMPmatch(const string& target, const string& pattern);


int main(){
	string S = "ababcaba1ba"; //Ŀ�괮  ;
	string T =  "abab" ; //ģʽ�� 
	int index;
	cout << BFMatch(&S, &T, &index) << endl;
	cout << BFmatch2("banananobano", "nano") << endl;
	cout << KMPmatch("banananobano", "nano") << endl;
	return 0;
}

//BF�㷨ģʽƥ��ʵ�ִ���1��O(MN)��
int BFMatch(string* S, string* T ,int* index){
	//inedx ����T��Sƥ��ʱ��ʼԪ�ص�����
	//�ɹ����� 1��ʧ�ܷ��� 0
	int flag = 0;
	int len_S = (*S).size();
	int len_T = (*T).size();
	if (len_S > len_T){
		for (int i = 0; i != len_S - len_T + 1; ++i){
			if ((*S)[i] ==(*T)[0]){
				for (int j = 0; j < len_T; ++j){
					if ((*S)[i + j] != (*T)[j]) break;

					//�ɹ�
					if (j == len_T - 1) {
						flag = 1;
						*index = i;
						return flag;
						//cout << "SUCEED!" << endl;
					}
				}
			}
		}
	}
	else{
		cout << "ERROR" << endl;
	}

	return flag;
}

//BF�㷨ģʽƥ��ʵ�ִ���2
int BFmatch2(const string& target, const string& pattern){
	int target_length = target.size();
	int pattern_length = pattern.size();
	int target_index = 0;
	int pattern_index = 0;
	while (target_index < target_length&&pattern_index < pattern_length){
		if (target[target_index] == pattern[pattern_index]){
			++target_index;
			++pattern_index;
		}
		else{
			target_index -= (pattern_index - 1);//����
			pattern_index = 0;
		}
	}
	if (pattern_index == pattern_length){
		return target_index - pattern_length;
	}  
	else
		return -1;
}

//KMP�㷨����
int* getNext(const string& pattern){
	int p_length = pattern.size();
	int* next = new int[p_length];
	next[0] = -1;
	int j = 0;
	int k = -1;
	while (j < p_length - 1){
		if (k == -1 || pattern[j] == pattern[k])
			next[++j] = ++k;
		else
			k = next[k];
	}
	return next;
}
int KMPmatch(const string& target, const string& pattern){
	int i = 0;//������λ��
	int j = 0;//ģʽ����λ��
	int* next = getNext(pattern);
	while (i < target.size()&& j < int(pattern.size())){
		if (j == -1 || target[i] == pattern[j]){//��j=-1ʱ��i,jͬʱ��1
			++i;
			++j;
		}
		else{
			j = next[j];
		}
	}
	if (j == pattern.size())
		return i - j;
	else
		return -1;
}