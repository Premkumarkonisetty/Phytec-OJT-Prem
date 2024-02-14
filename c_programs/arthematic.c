#include<stdio.h>
int main()
{
	int a,b,sum,sub,mul,div;
	printf("Enter number 1: ");
	scanf("%d",&a);
	printf("Enter number 2: ");
	scanf("%d",&b);
	sum=a+b;
	sub=a-b;
	mul=a*b;
	div=a/b;
	printf("The addition is: %d\n",sum);
	printf("The suutration is: %d\n",sub);
	printf("The multiplication is: %d\n",mul);
	printf("The division is: %d\n",div);
}

