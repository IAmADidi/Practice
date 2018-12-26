//1.用二维数组（char类型）来表示地图
//(1)地雷布局地图（用'0'表示不是地雷，'1'表示是地雷）
//(2)玩家看到的地图(哪些位置未翻开，哪些已翻开)
//2.初始化
//(1)地雷的布局，将该二维数组全部初始化为'0'，再随机设定若干地雷
//(2)' '表示未翻开
//3.先打印地图（玩家看的地图），提示玩家输入坐标,校验玩家输入的坐标是否合法
//4.如果翻得是地雷，游戏失败
//5.如果翻开的不是地雷且是最后一个不是地雷的位置，提示游戏成功
//6.如果翻开的不是地雷且不是最后一个非地雷位置，展开这个位置，并更新这个位置周
//围8个格子的地雷数目
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define MINE_COUNT 9
int Menu()
{
	int choice=0;
	printf("========================\n");
	printf("       0.结束游戏       \n");
	printf("       1.开始游戏       \n");
	printf("========================\n");
	scanf("%d", &choice);
	return choice;
}
void Init(char show_map[ROW+2][COL+2],char mine_map[ROW+2][COL+2])
{
	//把show_map初始化为' '
	for (int row = 0; row < ROW+2; row++)
	{
		for (int col = 0; col < COL+2; col++)
			show_map[row][col] = ' ';
	}
	//把mine_map初始化为全'0'
	for (int row = 0; row < ROW+2; row++)
	{
		for (int col = 0; col < COL+2; col++)
			mine_map[row][col] = '0';
	}
	//在mine_map中放置地雷
	int mine_count = MINE_COUNT;
	while (mine_count>0)
	{
		int row = rand() % ROW + 1;//[1,9]
		int col = rand() % COL + 1;
		if (mine_map[row][col] == '1')
		{
			//当前位置已经有地雷了
			continue;
		}
		mine_map[row][col] = '1';
		mine_count--;
	}
}
void DisplayMap(char map[ROW + 2][COL + 2])
{
	//打印左上角空白
	printf("   ");
	//打印列坐标
	for (int i = 1; i <= ROW; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	//打印分割线
	for (int i = 1; i <= ROW; i++)
	{
		printf("---");
	}
	printf("\n");
	//打印地图内容
	for (int row = 1; row <= ROW; row++)
	{
		//行号
		printf("%d| ", row);
		//打印该行每一列
		for (int col = 1; col <= COL; col++)
		{
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
void UpdateShowMap(char show_map[ROW + 2][COL + 2],
	char mine_map[ROW + 2][COL + 2],int row, int col)
{
	int count = 0;
	//统计当前位置周围8个位置坐标
	count = (mine_map[row - 1][col - 1] - '0') +
		(mine_map[row - 1][col] - '0') +
		(mine_map[row - 1][col + 1] - '0') +
		(mine_map[row][col - 1] - '0') +
		(mine_map[row][col + 1] - '0') +
		(mine_map[row + 1][col - 1] - '0') +
		(mine_map[row + 1][col] - '0') +
		(mine_map[row + 1][col + 1] - '0');
	show_map[row][col] = '0' + count;

}
//调用一次开始一局
void Game()
{
	//加2为了加一层边框，边框可以
	//再后面判断某一位置周围8个位置的地雷情况时不用考虑数组越界问题
	char show_map[ROW + 2][COL + 2];
	char mine_map[ROW + 2][COL + 2];
	//数组参数隐式为指针
	Init(show_map,mine_map);
	int safe_blank_count = 0;
	while (1)
	{
		DisplayMap(show_map);
		int row = 0, col = 0;
		printf("请输入坐标：");
		scanf("%d %d", &row, &col);
		if (row<1 || row>ROW || col<1 || col>COL)
		{
			//坐标非法
			printf("您输入的坐标不合法，请重新输入\n");
			continue;
		}
		//验证是否踩到地雷
		if (mine_map[row][col] == '1')
		{
			printf("游戏结束，扫雷失败！\n");
			return;
		}
		safe_blank_count++;
		//验证是否扫雷成功
		if (safe_blank_count == ROW*COL - MINE_COUNT)
		{
			printf("游戏结束，扫雷成功！\n");
			return;
		}
		UpdateShowMap(show_map, mine_map, row, col);
		system("cls");
	}
}
int main()
{
	srand((unsigned int)time(0));
	while (1)
	{
		int choice = Menu();
		if (choice == 0)
		{
			printf("goodbye!\n");
			break;
		}
		if (choice == 1)
			Game();
	}
	system("pause");
	return 0;
}