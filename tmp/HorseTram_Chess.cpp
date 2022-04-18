#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
//�������̴�С
#define N 6
#define X N
#define Y N 
int chess[X][Y];
//�ҵ�����λ�ã�x,y������һ���ɶ�λ��
//count�ǵڼ���λ�ã���8��
int next_pos(int* x, int* y, int count){
	switch (count)
	{
	case 0:
		if (*x - 2 >= 0 && *y - 1 >= 0 && chess[*x - 2][*y - 1] == 0)
		{
			*x -= 2;
			*y -= 1; //x,yָ����һ����
			return 1;
		}
		break;
	case 1:
		if (*x - 2 >= 0 && *y + 1 <= Y - 1 && chess[*x - 2][*y + 1] == 0)
		{
			*x -= 2;
			*y += 1; //x,yָ����һ����
			return 1;
		}
		break;
	case 2:
		if (*x - 1 >= 0 && *y + 2 <= Y - 1 && chess[*x - 1][*y + 2] == 0)
		{
			*x -= 1;
			*y += 2; //x,yָ����һ����
			return 1;
		}
		break;
	case 3:
		if (*x + 1 <= X - 1 && *y + 2 <= Y - 1 && chess[*x + 1][*y + 2] == 0)
		{
			*x += 1;
			*y += 2; //x,yָ����һ����
			return 1;
		}
		break;
	case 4:
		if (*x + 2 <= X - 1 && *y + 1 <= Y - 1 && chess[*x + 2][*y + 1] == 0)
		{
			*x += 2;
			*y += 1;//x,yָ����һ����		
			return 1;
		}
		break;
	case 5:
		if (*x + 2 <= X - 1 && *y - 1 >= 0 && chess[*x + 2][*y - 1] == 0)
		{
			*x += 2;
			*y -= 1;//x,yָ����һ����		
			return 1;
		}
		break;
	case 6:
		if (*x + 1 <= X - 1 && *y - 2 >= 0 && chess[*x + 1][*y - 2] == 0)
		{
			*x += 1;
			*y -= 2;//x,yָ����һ����			
			return 1;
		}
		break;
	case 7:
		if (*x - 1 >= 0 && *y - 2 >= 0 && chess[*x - 1][*y - 2] == 0)
		{
			*x -= 1;
			*y -= 2;//x,yָ����һ����			
			return 1;
		}
		break;
	default:
		break;
	}
	return 0; //��һ����·����
}

//������ȱ������̣�tag�Ǳ�Ǳ�����ÿ��һ����tag++
int TravelChessBoard(int x, int y, int tag){
	cout << tag <<endl;
	int x1 = x, y1 = y, flag = 0, count = 0;
	chess[x][y] = tag; //
	if (tag == X*Y){
		//��ӡ����
		return 1;
	}

	//�ҵ���һ�����ߵ�����
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

		//�����ҵ������һ����������
		x1 = x; //�ϴε��ú�����x����
		y1 = y; //�ϴε��ú�����y����
		count++;//����count++��ԭ�����ϴε��ú���ʱ�Ѹ�ֵcount=0
		flag = next_pos(&x1, &y1, count);
		while (flag == 0 && count < Y-1)
		{
			count++;
			flag = next_pos(&x1, &y1, count);
		}
	}

	if (flag == 0)
	{
		chess[x][y] = 0; //�������λ����0
	}

	return 0;
}

//��ӡ����
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
	//��ʼ������
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