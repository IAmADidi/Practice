#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*1.在屏幕上输出以下图案：
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
	/*2.求出0～999之间的所有“水仙花数”并输出。
		“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。*/
	/*for (int x = 100; x < 1000; x++)
	{
		int t1 = x % 10;
		int t2 = x / 10 % 10;
		int t3 = x / 100;
		if (t1*t1*t1 + t2*t2*t2 + t3*t3*t3 == x)
			printf("%d   ", x);
	}*/
	/*3.
		求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
		例如：2 + 22 + 222 + 2222 + 22222*/
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