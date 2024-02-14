#include<stdio.h>
int main()
{
	int a,b;
	printf("before swapping:");
	scanf("%d %d",&a,&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("After swapping a=%d,b=%d",a,b);
	return 0;
}
