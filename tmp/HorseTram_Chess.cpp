#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
//定义棋盘大小
#define N 6
#define X N
#define Y N 
int chess[X][Y];
//找到基于位置（x,y）的下一个可定位置
//count是第几个位置，共8种
int next_pos(int* x, int* y, int count){
	switch (count)
	{
	case 0:
		if (*x - 2 >= 0 && *y - 1 >= 0 && chess[*x - 2][*y - 1] == 0)
		{
			*x -= 2;
			*y -= 1; //x,y指向下一个点
			return 1;
		}
		break;
	case 1:
		if (*x - 2 >= 0 && *y + 1 <= Y - 1 && chess[*x - 2][*y + 1] == 0)
		{
			*x -= 2;
			*y += 1; //x,y指向下一个点
			return 1;
		}
		break;
	case 2:
		if (*x - 1 >= 0 && *y + 2 <= Y - 1 && chess[*x - 1][*y + 2] == 0)
		{
			*x -= 1;
			*y += 2; //x,y指向下一个点
			return 1;
		}
		break;
	case 3:
		if (*x + 1 <= X - 1 && *y + 2 <= Y - 1 && chess[*x + 1][*y + 2] == 0)
		{
			*x += 1;
			*y += 2; //x,y指向下一个点
			return 1;
		}
		break;
	case 4:
		if (*x + 2 <= X - 1 && *y + 1 <= Y - 1 && chess[*x + 2][*y + 1] == 0)
		{
			*x += 2;
			*y += 1;//x,y指向下一个点		
			return 1;
		}
		break;
	case 5:
		if (*x + 2 <= X - 1 && *y - 1 >= 0 && chess[*x + 2][*y - 1] == 0)
		{
			*x += 2;
			*y -= 1;//x,y指向下一个点		
			return 1;
		}
		break;
	case 6:
		if (*x + 1 <= X - 1 && *y - 2 >= 0 && chess[*x + 1][*y - 2] == 0)
		{
			*x += 1;
			*y -= 2;//x,y指向下一个点			
			return 1;
		}
		break;
	case 7:
		if (*x - 1 >= 0 && *y - 2 >= 0 && chess[*x - 1][*y - 2] == 0)
		{
			*x -= 1;
			*y -= 2;//x,y指向下一个点			
			return 1;
		}
		break;
	default:
		break;
	}
	return 0; //下一步无路可走
}

//深度优先遍历棋盘，tag是标记变量，每走一步，tag++
int TravelChessBoard(int x, int y, int tag){
	cout << tag <<endl;
	int x1 = x, y1 = y, flag = 0, count = 0;
	chess[x][y] = tag; //
	if (tag == X*Y){
		//打印棋盘
		return 1;
	}

	//找到下一个可走的坐标
	flag = next_pos(&x1, &y1, count);
	while (flag == 0 && count < 7)
	{
		count++;
		flag = next_pos(&x1, &y1, count);
	}
	while (flag)
	{
		if (TravelChessBoard(x1, y1, tag + 1))
		{
			return 1;
		}

		//继续找到马的下一步可走坐标
		x1 = x; //上次调用函数的x坐标
		y1 = y; //上次调用函数的y坐标
		count++;//这里count++的原因是上次调用函数时已赋值count=0
		flag = next_pos(&x1, &y1, count);
		while (flag == 0 && count < Y-1)
		{
			count++;
			flag = next_pos(&x1, &y1, count);
		}
	}

	if (flag == 0)
	{
		chess[x][y] = 0; //不满足的位置置0
	}

	return 0;
}

//打印棋盘
void printchess(){
	int i, j;
	for (i = 0; i < X; ++i)
	{
		for (j = 0; j < Y; ++j)
			cout << left<<setw(3)<<chess[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

int main(){
	int i, j;
	//初始化棋盘
	for (i = 0; i < X; ++i)
		for (j = 0; j < Y; ++j)
			chess[i][j] = 0;
	clock_t start, end;
	start = clock();
	int state = TravelChessBoard(4, 5, 1);
	end = clock();
	if (!state)
		cout << "Failed!" << endl;
	else
	{
		printchess();
		cout << "The cost time is " << (double)(end - start) / CLOCKS_PER_SEC << " s" << endl;
	}
	
	return 0;
}