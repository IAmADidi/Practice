#include<stdio.h>
#include<math.h>
void gen1(double a,double b,double c)
{
    double x1,x2;
    x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    x2=(-b-sqrt(b*b-4*a*c))/(2*a);
    printf("�����Ľ�Ϊx1=%.2f,x2=%.2f",x1,x2);
}
void gen2(double a,double b,double c)
{
    double x;
    x=-b/(2*a);
    printf("�����Ľ�Ϊx=%.2f",x);
}
void gen3()
{
    printf("�޽�");
}
int main()
{
    double a,b,c,m;
    printf("������һԪ���β���ʽ��ϵ��a,b,c��ֵ\n");
    scanf("%lf%lf%lf",&a,&b,&c);
    m=b*b-4*a*c;
    if(m>0)
        gen1(a,b,c);
    else if(m==0)
        gen2(a,b,c);
    else
        gen3();
    return 0;

}
