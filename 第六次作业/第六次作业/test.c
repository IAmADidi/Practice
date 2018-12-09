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
	if (year % 4 == 0)             /*用if函数逐步判断是否满足成为闰年的条件*/
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				leap = 1;         /*满足给leap赋值1*/
			else
				leap = 0;         /*不满足给leap赋值0*/
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
	//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
	//	输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
	/*int cow=0,col=0;
	printf("请输入要打印的口诀表行数和列数\n");
	scanf_s("%d%d", &cow, &col);
	PrintTable(cow, col);*/
	//2.使用函数实现两个数的交换.
	/*int a = 10, b = 20;
	swap(&a, &b);*/
	//3.实现一个函数判断year是不是润年。
	 //4. 创建一个数组，实现函数init（）初始化数组、实现empty（）清空数组、
	 //实现reverse（）函数完成数组元素的逆置。
	 //要求：自己设计函数的参数，返回值。
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
	//5.实现一个函数，判断一个数是不是素数。
	int n=0;
	scanf_s("%d", &n);
	int x = PrimeNumber(n);
	if (x == 0)
		printf("%d不是素数\n", n);
	else printf("%d是素数\n", n);
    
	system("pause");
	return 0;
}