#include<stdio.h>
#include<stdlib.h>
//1.��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
unsigned int reverse_bit(unsigned int value)
{
	unsigned int ret = 0;
	int i;
	for (i = 0; i < 32; i++)
	{
		ret = ret << 1;
		//��value��ǰ���������һλ��˳�����ret
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
	//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
	/*int a = 8;
	int b = 3;

	printf("%d",b+((a-b) >> 1));*/
	/*3.���ʵ�֣�
		һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
		���ҳ�������֡���ʹ��λ���㣩*/
	/*int arr[5] = { 1, 5, 3, 1, 3 };
	int ret = arr[0];
	for (int i = 1; i < 5; i++)
	{
		ret = ret^arr[i];
	}

	printf("The number is:%d",ret);*/
	/*4.
	��һ���ַ����������Ϊ:"student a am i",
				���㽫��������ݸ�Ϊ"i am a student".
				Ҫ��
				����ʹ�ÿ⺯����
				ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

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