//**************************************
//程序采用递归的方法实现八皇后问题
//2015/11/4
//**************************************
#include <iostream>
#include <fstream>
using namespace std;
#define N 8

int mycount = 0;
ofstream ofs("EightQueueResults.txt");//将结果输出保存到当前路径EightQueueResults.txt中
//ofstream ofs("D:\\EightQueueResults.txt")//将结果输出保存到D盘EightQueueResults.txt中


int InitArray(int(*chess)[N]){
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			chess[i][j] = 0;
	return 0;
}

int notDanger(int row, int j, int (*chess)[N]){
	int i, k;
	int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;

	//判断列方向是否有危险
	for (i = 0; i < N; ++i){
		if (*(*(chess + i) + j) != 0){
			flag1 = 1;
			break;
		}
	}

	//判断左上方
	for (i = row, k = j; i >= 0 && k >= 0; i--, k--){
		if (*(*(chess + i) + k) != 0){
			flag2 = 1;
			break;
		}
	}

	//判断左下方
	for (i = row, k = j; i <N && k >= 0; i++, k--){
		if (*(*(chess + i) + k) != 0){
			flag3 = 1;
			break;
		}
	}

	//判断右上方
	for (i = row, k = j; i >= 0 && k <N; i--, k++){
		if (*(*(chess + i) + k) != 0){
			flag4 = 1;
			break;
		}
	}

	//判断右下方
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

//row表示起始行
//col表示列数
//(*chess)[0]表示指向每一行的指针
void EightQueen(int row,int col,int (*chess)[N]){
	//定义一个临时棋盘,并初始化为chess
	int chess_temp[N][N], i, j; 
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			chess_temp[i][j] = chess[i][j];
	if (row == N){
		cout << "打印第" << mycount + 1 << "种棋盘" << endl;
		ofs << "打印第" << mycount + 1 << "种棋盘" << endl;
		for (i = 0; i < N; ++i){
			for (j = 0; j < N; ++j)
			{
				cout << *(*(chess_temp + i) + j) << " ";
				ofs << *(*(chess_temp + i) + j) << " ";
			}
			cout << endl; //打印完一行增加一个回车
			ofs << endl;
		}
		cout << endl;
		ofs << endl;
		++mycount;

	}
	else{
		//判断该位置是否合适 
		//如果没有危险，继续往下
		for (j = 0; j < col; ++j){
			if (notDanger(row, j, chess)){//判断是row行j列元素是否危险，不危险返回1
				for (i = 0; i < N; ++i){
					*(*(chess_temp + row) + i) = 0;
				}
				*(*(chess_temp + row) + j) = 1; //row行j列赋值为1，其余为0
				EightQueen(row + 1, col, chess_temp); //递归，往下一行进行测试
			} 
		}

	}
}


int main(){
	int chess[N][N], i, j;
	int count = 1;
	InitArray(chess);
	//棋盘初始化
	//cout << *(*(chess + 0) + 0);
	EightQueen(0, N, chess);

	
	return 0;
}