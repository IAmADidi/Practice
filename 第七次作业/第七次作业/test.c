#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Fib(int n)//斐波那契数使用递归
{
	if (n == 1 || n == 2)
		return 1;
	else return Fib(n - 1) + Fib(n - 2);
}
int fib(int n)//斐波那契数不使用递归
{
	int f0 = 1, f1 = 1, f2;
	for (int i = 2; i < n; i++)
	{
		f2 = f0 + f1;
		f0 = f1;
		f1 = f2;
	}
	return f2;
}
int Pow(int n,int k)
{
	if (k>0)
		return n*Pow(n, k - 1);
	return 1;
}
int DigitSum(int n)
{
	int sum = 0;
	sum= n % 10;
	if (n > 9)
		sum=sum + DigitSum(n / 10);
	
	return sum;
}
void reverse_string(char * s)
{
	int len=0;
	while (s[len] != 0)
		len++;
	if (len > 1)
	{
		char temp = s[0];
		s[0] = s[len - 1];
		s[len - 1] = '\0';
		reverse_string(s + 1);
		s[len - 1] = temp;
	}
}
int My_strlen(char* s)//使用递归
{
	int len = 0;
	if (*s != 0)
	{
		len++; 
		len += My_strlen(++s);
	}
	 return len;
}
int my_strlen(char* s)//不使用递归
{
	int len = 0;
	while (s[len] != 0)
		len++;
	return len;
}
int Fac(int n)//使用递归
{
	if (n == 1)return 1;
	return n*Fac(n - 1);
}
int fac(int n)
{
	int i,x=1;
	for (i = 1; i <= n; i++)
		x = x*i;
	return x;
}
void PrintNum(int n)
{
	if (n > 9)PrintNum(n / 10);
	printf("%d   ", n % 10);
}
int main()
{
	//递归和非递归分别实现求第n个斐波那契数。 
	/*int n;
	scanf_s("%d", &n);
	printf("%d", fib(n));*/
	//编写一个函数实现n^k，使用递归实现 
	/*int n, k;
	scanf_s("%d%d", &n, &k);
	printf("%d^%d=%d",n,k, Pow(n, k));*/
	//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
	//	例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
	/*printf("%d", DigitSum(1729));
	system("pause");*/
	//4. 编写一个函数 reverse_string(char * string)（递归实现）
	//   实现：将参数字符串中的字符反向排列。
	//	要求：不能使用C函数库中的字符串操作函数。
	//char ch[10]="China";
	//reverse_string(ch);
	//printf("%s", ch);
	//5.递归和非递归分别实现strlen
	/*char s[10] ={0};
	scanf("%s", s);
	printf("%d   %d\n", My_strlen(s),my_strlen(s));*/
	//6.递归和非递归分别实现求n的阶乘
	/*int n;
	scanf("%d", &n);
	printf("%d   %d", Fac(n), fac(n));*/
	//7.递归方式实现打印一个整数的每一位
	int n;
	scanf("%d", &n);
	PrintNum(n);
	system("pause");
	return 0;
}