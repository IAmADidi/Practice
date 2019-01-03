#include<stdio.h>
#include<stdlib.h>
//1.这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
unsigned int reverse_bit(unsigned int value)
{
	unsigned int ret = 0;
	int i;
	for (i = 0; i < 32; i++)
	{
		ret = ret << 1;
		//将value当前二进制最后一位按顺序放入ret
		ret = ret | (value >> i) & 1;

	}
	return ret;
}
int My_Strlen(char *s)
{
	int count = 0;
	while (*s != 0)
	{
		count++;
		s++;
	}
	return count;
}
void reverse_word(char* left, char* right)
{
	while (left < right)
	{
		char t = *left;
		*left = *right;
		*right = t;
		left++;
		right--;
	}
}
void reverse(char* p)
{
	char* start = p;
	char* end = NULL;
	while (*p)
	{
		start = p;
		while ((*p != ' ')&&(*p))
			p++;
		 end = p -1;
		reverse_word(start, end);
		if (*p == ' ')
			p++;
	}
}
int main()
{
	//printf("%u\n",reverse_bit(25) );
	//2.不使用（a + b） / 2这种方式，求两个数的平均值。
	/*int a = 8;
	int b = 3;

	printf("%d",b+((a-b) >> 1));*/
	/*3.编程实现：
		一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
		请找出这个数字。（使用位运算）*/
	/*int arr[5] = { 1, 5, 3, 1, 3 };
	int ret = arr[0];
	for (int i = 1; i < 5; i++)
	{
		ret = ret^arr[i];
	}

	printf("The number is:%d",ret);*/
	/*4.
	有一个字符数组的内容为:"student a am i",
				请你将数组的内容改为"i am a student".
				要求：
				不能使用库函数。
				只能开辟有限个空间（空间个数和字符串的长度无关）。

				student a am i
				i ma a tneduts
				i am a student*/
	char s[] = "student a am i";
	printf("%s\n", s);
	reverse_word(s, s + My_Strlen(s) - 1);
	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);
	system("pause");
	return 0;
}