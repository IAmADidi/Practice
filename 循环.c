#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*1.����Ļ���������ͼ����
		*
		***
		*****
		*******
		*********
		***********
		*************
		***********
		*********
		*******
		*****
		***
		**
		*/
	/*for (int i = 1; i <= 7; i++)
	{
		for (int st = 1; st <= 2 * i - 1; st++)
			printf("*");
		printf("\n");
	}
	for (int i = 1; i <= 6; i++)
	{
		for (int st =1 ; st <= 11+(i-1)*(-2); st++)
			printf("*");
		printf("\n");
	}*/
	/*2.���0��999֮������С�ˮ�ɻ������������
		��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3 ? ����153��һ����ˮ�ɻ�������*/
	/*for (int x = 100; x < 1000; x++)
	{
		int t1 = x % 10;
		int t2 = x / 10 % 10;
		int t3 = x / 100;
		if (t1*t1*t1 + t2*t2*t2 + t3*t3*t3 == x)
			printf("%d   ", x);
	}*/
	/*3.
		��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
		���磺2 + 22 + 222 + 2222 + 22222*/
	int Sn = 0, a;
	scanf("%d", &a);
	int t =0;
	for (int i = 0; i < 5; i++)
	{
		t = t * 10 + a;
		Sn += t;
	}
	printf("Sn=%d\n", Sn);
	system("pause");
	return 0;
}