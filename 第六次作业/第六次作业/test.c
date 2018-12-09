#include<stdio.h>
#include<stdlib.h>
void PrintTable(int cow, int col)
{
	int i, j;
	for (i = 1; i <= cow; i++)
	{
		for (j = 1; j <= col; j++)
			printf("%3d*%3d=%3d", i, j, i*j);
		printf("\n");
	}
}
void swap(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int LeapYear(int year)
{
	int leap;
	if (year % 4 == 0)             /*��if�������ж��Ƿ������Ϊ���������*/
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				leap = 1;         /*�����leap��ֵ1*/
			else
				leap = 0;         /*�������leap��ֵ0*/
		}
		else
			leap = 1;
	}
	else
		leap = 0;
	return leap;
}
void init(int a[])
{
	for (int i = 0; i < 10; i++)
		scanf_s("%d", a + i);
}
void empty(int a[])
{
	for (int i = 0; i < 10; i++)
		a[i] = 0;
}
void reverse(int a[])
{
	int t;
	for (int i = 0; i <= 10 / 2 - 1; i++)
	{
		t = a[i];
		a[i] = a[10 - i - 1];
		a[10 - i - 1] = t;
	}
}
int PrimeNumber(int n)
{
	int i;
	for ( i=2; i <n ;i++)
	if (n%i == 0)
		break;
	if (i==n) return 1;
	else return 0;

}
int main()
{
	//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
	//	����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
	/*int cow=0,col=0;
	printf("������Ҫ��ӡ�Ŀھ�������������\n");
	scanf_s("%d%d", &cow, &col);
	PrintTable(cow, col);*/
	//2.ʹ�ú���ʵ���������Ľ���.
	/*int a = 10, b = 20;
	swap(&a, &b);*/
	//3.ʵ��һ�������ж�year�ǲ������ꡣ
	 //4. ����һ�����飬ʵ�ֺ���init������ʼ�����顢ʵ��empty����������顢
	 //ʵ��reverse���������������Ԫ�ص����á�
	 //Ҫ���Լ���ƺ����Ĳ���������ֵ��
	/*int a[10] = { 0 };
	init(a);
	for (int i = 0; i < 10; i++)
		printf("%5d", a[i]);
	printf("\n");
	reverse(a);
	for (int i = 0; i < 10; i++)
		printf("%5d", a[i]);
	printf("\n");
	empty(a);*/
	//5.ʵ��һ���������ж�һ�����ǲ���������
	int n=0;
	scanf_s("%d", &n);
	int x = PrimeNumber(n);
	if (x == 0)
		printf("%d��������\n", n);
	else printf("%d������\n", n);
    
	system("pause");
	return 0;
}