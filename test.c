#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//g_表示全局变量
char g_broad[ROW][COL];
void Init()
{
	//把数组中的每个元素都初始化成' '
	for (int row = 0; row< ROW;row++)
		for (int col = 0; col < COL; col++)
			g_broad[row][col] = ' ';
}
void Print()
{
	for (int row = 0; row < ROW; row++)
	{
		printf("| %c | %c | %c |\n", g_broad[row][0], g_broad[row][1],
			g_broad[row][2]);
		printf("----|---|---|\n");
	}
}
void PlayerMove()
{
	printf("玩家落子");
	while(1)
	{
		printf("请输入一组坐标(row col):");
		int row = 0, col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			//用户输入的坐标非法
			printf("坐标输入非法，请重新输入!n");
			continue;
		}
		if (g_broad[row][col] != ' ')
		{
			printf("当前位置已经有子了，请重新输入！\n");
			continue;
		}
		g_broad[row][col] = 'x';
		break;
	}
}
//返回了当前游戏的胜负情况，返回'X'表示玩家获胜，返回'O'表示电脑胜利，
//返回'q' 表示和棋，返回' '表示没有结束
int IsFull()
{
	//如果棋盘满了返回1，没有返回0
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL;col++)
		if (g_broad[row][col] == ' ')return 0;
	}
	//如果遍历结束也没找到空格说明
	return 1;
}
char CheckWinner()
{
	//检查所有行
	for (int row = 0; row < ROW; row++)
	{
		if (g_broad[row][0] == g_broad[row][1]
			&& g_broad[row][1] == g_broad[row][2] && g_broad[row][0] != ' '){
			return g_broad[row][0];
		}
	}
	//检查所有列
	for (int col = 0; col < COL; col++)
	{
		if (g_broad[0][col] == g_broad[1][col]
			&& g_broad[1][col] == g_broad[2][col] && g_broad[0][col] != ' ')
			return g_broad[0][col];
	}
	//检查对角线
	if (g_broad[0][0] == g_broad[1][1]
		&& g_broad[0][0] == g_broad[2][2]&&
		g_broad[0][0] != ' ')
		return g_broad[0][0];
	if (g_broad[0][2] == g_broad[1][1]
		&& g_broad[0][2] == g_broad[2][0] &&
		g_broad[0][2] != ' ')
		return g_broad[0][0];
	if (IsFull())
		return 'q';
	return ' ';
}
void ComputerMove()
{
	//让电脑产生两个随机数
	printf("电脑落子！\n");
	while (1){
		int row = rand() % ROW;
		int col = rand() % COL;
		if (g_broad[row][col] != ' ')
		{
			continue;
		}
		g_broad[row][col] = 'o';
		break;
	}
}
int main()
{
	srand((unsigned) time(0));
	Init();
	char winner = 0;
	while (1)
	{
		Print();
		PlayerMove();
		winner = CheckWinner();
		if (winner != ' ')
		{
			break;
		}
		ComputerMove();
		system("cls");
		if (winner != ' ')
		{
			break;
		}
	}
	if (winner == 'x')
		printf("你赢了！\n");
	else if (winner == 'o')
		printf("你输了\n");
	else if (winner == 'q')
		printf("和棋！你和电脑55开!\n");
	system("pause");
	return 0;
}