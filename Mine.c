//1.�ö�ά���飨char���ͣ�����ʾ��ͼ
//(1)���ײ��ֵ�ͼ����'0'��ʾ���ǵ��ף�'1'��ʾ�ǵ��ף�
//(2)��ҿ����ĵ�ͼ(��Щλ��δ��������Щ�ѷ���)
//2.��ʼ��
//(1)���׵Ĳ��֣����ö�ά����ȫ����ʼ��Ϊ'0'��������趨���ɵ���
//(2)' '��ʾδ����
//3.�ȴ�ӡ��ͼ����ҿ��ĵ�ͼ������ʾ�����������,У���������������Ƿ�Ϸ�
//4.��������ǵ��ף���Ϸʧ��
//5.��������Ĳ��ǵ����������һ�����ǵ��׵�λ�ã���ʾ��Ϸ�ɹ�
//6.��������Ĳ��ǵ����Ҳ������һ���ǵ���λ�ã�չ�����λ�ã����������λ����
//Χ8�����ӵĵ�����Ŀ
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
	printf("       0.������Ϸ       \n");
	printf("       1.��ʼ��Ϸ       \n");
	printf("========================\n");
	scanf("%d", &choice);
	return choice;
}
void Init(char show_map[ROW+2][COL+2],char mine_map[ROW+2][COL+2])
{
	//��show_map��ʼ��Ϊ' '
	for (int row = 0; row < ROW+2; row++)
	{
		for (int col = 0; col < COL+2; col++)
			show_map[row][col] = ' ';
	}
	//��mine_map��ʼ��Ϊȫ'0'
	for (int row = 0; row < ROW+2; row++)
	{
		for (int col = 0; col < COL+2; col++)
			mine_map[row][col] = '0';
	}
	//��mine_map�з��õ���
	int mine_count = MINE_COUNT;
	while (mine_count>0)
	{
		int row = rand() % ROW + 1;//[1,9]
		int col = rand() % COL + 1;
		if (mine_map[row][col] == '1')
		{
			//��ǰλ���Ѿ��е�����
			continue;
		}
		mine_map[row][col] = '1';
		mine_count--;
	}
}
void DisplayMap(char map[ROW + 2][COL + 2])
{
	//��ӡ���Ͻǿհ�
	printf("   ");
	//��ӡ������
	for (int i = 1; i <= ROW; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	//��ӡ�ָ���
	for (int i = 1; i <= ROW; i++)
	{
		printf("---");
	}
	printf("\n");
	//��ӡ��ͼ����
	for (int row = 1; row <= ROW; row++)
	{
		//�к�
		printf("%d| ", row);
		//��ӡ����ÿһ��
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
	//ͳ�Ƶ�ǰλ����Χ8��λ������
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
//����һ�ο�ʼһ��
void Game()
{
	//��2Ϊ�˼�һ��߿򣬱߿����
	//�ٺ����ж�ĳһλ����Χ8��λ�õĵ������ʱ���ÿ�������Խ������
	char show_map[ROW + 2][COL + 2];
	char mine_map[ROW + 2][COL + 2];
	//���������ʽΪָ��
	Init(show_map,mine_map);
	int safe_blank_count = 0;
	while (1)
	{
		DisplayMap(show_map);
		int row = 0, col = 0;
		printf("���������꣺");
		scanf("%d %d", &row, &col);
		if (row<1 || row>ROW || col<1 || col>COL)
		{
			//����Ƿ�
			printf("����������겻�Ϸ�������������\n");
			continue;
		}
		//��֤�Ƿ�ȵ�����
		if (mine_map[row][col] == '1')
		{
			printf("��Ϸ������ɨ��ʧ�ܣ�\n");
			return;
		}
		safe_blank_count++;
		//��֤�Ƿ�ɨ�׳ɹ�
		if (safe_blank_count == ROW*COL - MINE_COUNT)
		{
			printf("��Ϸ������ɨ�׳ɹ���\n");
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