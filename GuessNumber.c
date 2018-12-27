#include<stdio.h>
#include<stdlib.h>

int Menu()
{
	printf("********************************\n");
	printf("       1.开始游戏\n");
	printf("       2.结束游戏\n");
	printf("********************************\n");
	printf("请输入您的选择\n");
	int choice = 0;
	scanf_s("%d", &choice);
	return choice;
}

void Game()
{
	int result = rand() % 100 + 1;
	while (1)
	{
		printf("请输入一个数字(1-100):");
		int num = 0;
		scanf_s("%d", &num);
		if (num > result)
			printf("高了！\n");
		else if (num < result)
			printf("低了！\n");
		else
		{
			printf("猜对了！\n");
			break;
		}
	}
}

int main()

{

	while (1)
	{
		int choice = Menu();
		if (choice == 1)
		{
			Game();
		}
		else if (choice == 2)
		{
			printf("游戏结束！\n");
			break;
		}

		system("pause");

		return 0;



	}
}