#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//g_��ʾȫ�ֱ���
char g_broad[ROW][COL];
void Init()
{
	//�������е�ÿ��Ԫ�ض���ʼ����' '
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
	printf("�������");
	while(1)
	{
		printf("������һ������(row col):");
		int row = 0, col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			//�û����������Ƿ�
			printf("��������Ƿ�������������!n");
			continue;
		}
		if (g_broad[row][col] != ' ')
		{
			printf("��ǰλ���Ѿ������ˣ����������룡\n");
			continue;
		}
		g_broad[row][col] = 'x';
		break;
	}
}
//�����˵�ǰ��Ϸ��ʤ�����������'X'��ʾ��һ�ʤ������'O'��ʾ����ʤ����
//����'q' ��ʾ���壬����' '��ʾû�н���
int IsFull()
{
	//����������˷���1��û�з���0
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL;col++)
		if (g_broad[row][col] == ' ')return 0;
	}
	//�����������Ҳû�ҵ��ո�˵��
	return 1;
}
char CheckWinner()
{
	//���������
	for (int row = 0; row < ROW; row++)
	{
		if (g_broad[row][0] == g_broad[row][1]
			&& g_broad[row][1] == g_broad[row][2] && g_broad[row][0] != ' '){
			return g_broad[row][0];
		}
	}
	//���������
	for (int col = 0; col < COL; col++)
	{
		if (g_broad[0][col] == g_broad[1][col]
			&& g_broad[1][col] == g_broad[2][col] && g_broad[0][col] != ' ')
			return g_broad[0][col];
	}
	//���Խ���
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
	//�õ��Բ������������
	printf("�������ӣ�\n");
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
		printf("��Ӯ�ˣ�\n");
	else if (winner == 'o')
		printf("������\n");
	else if (winner == 'q')
		printf("���壡��͵���55��!\n");
	system("pause");
	return 0;
}