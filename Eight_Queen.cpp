//**************************************
//������õݹ�ķ���ʵ�ְ˻ʺ�����
//2015/11/4
//**************************************
#include <iostream>
#include <fstream>
using namespace std;
#define N 8

int mycount = 0;
ofstream ofs("EightQueueResults.txt");//�����������浽��ǰ·��EightQueueResults.txt��
//ofstream ofs("D:\\EightQueueResults.txt")//�����������浽D��EightQueueResults.txt��


int InitArray(int(*chess)[N]){
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			chess[i][j] = 0;
	return 0;
}

int notDanger(int row, int j, int (*chess)[N]){
	int i, k;
	int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;

	//�ж��з����Ƿ���Σ��
	for (i = 0; i < N; ++i){
		if (*(*(chess + i) + j) != 0){
			flag1 = 1;
			break;
		}
	}

	//�ж����Ϸ�
	for (i = row, k = j; i >= 0 && k >= 0; i--, k--){
		if (*(*(chess + i) + k) != 0){
			flag2 = 1;
			break;
		}
	}

	//�ж����·�
	for (i = row, k = j; i <N && k >= 0; i++, k--){
		if (*(*(chess + i) + k) != 0){
			flag3 = 1;
			break;
		}
	}

	//�ж����Ϸ�
	for (i = row, k = j; i >= 0 && k <N; i--, k++){
		if (*(*(chess + i) + k) != 0){
			flag4 = 1;
			break;
		}
	}

	//�ж����·�
	for (i = row, k = j; i <N && k <N; i++, k++){
		if (*(*(chess + i) + k) != 0){
			flag5 = 1;
			break;
		}
	}

	if (flag1 || flag2 || flag3 || flag4 || flag5){
		return 0;
	}
	else{
		return 1;
	}
}

//row��ʾ��ʼ��
//col��ʾ����
//(*chess)[0]��ʾָ��ÿһ�е�ָ��
void EightQueen(int row,int col,int (*chess)[N]){
	//����һ����ʱ����,����ʼ��Ϊchess
	int chess_temp[N][N], i, j; 
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			chess_temp[i][j] = chess[i][j];
	if (row == N){
		cout << "��ӡ��" << mycount + 1 << "������" << endl;
		ofs << "��ӡ��" << mycount + 1 << "������" << endl;
		for (i = 0; i < N; ++i){
			for (j = 0; j < N; ++j)
			{
				cout << *(*(chess_temp + i) + j) << " ";
				ofs << *(*(chess_temp + i) + j) << " ";
			}
			cout << endl; //��ӡ��һ������һ���س�
			ofs << endl;
		}
		cout << endl;
		ofs << endl;
		++mycount;

	}
	else{
		//�жϸ�λ���Ƿ���� 
		//���û��Σ�գ���������
		for (j = 0; j < col; ++j){
			if (notDanger(row, j, chess)){//�ж���row��j��Ԫ���Ƿ�Σ�գ���Σ�շ���1
				for (i = 0; i < N; ++i){
					*(*(chess_temp + row) + i) = 0;
				}
				*(*(chess_temp + row) + j) = 1; //row��j�и�ֵΪ1������Ϊ0
				EightQueen(row + 1, col, chess_temp); //�ݹ飬����һ�н��в���
			} 
		}

	}
}


int main(){
	int chess[N][N], i, j;
	int count = 1;
	InitArray(chess);
	//���̳�ʼ��
	//cout << *(*(chess + 0) + 0);
	EightQueen(0, N, chess);

	
	return 0;
}