#include<stdio.h>
int main()
{
	int i,n,t1=0,t2=1,x=t1+t2;
	printf("Enter the no of terms:");
	scanf("%d",&n);
	printf("The fibonacci series %d,%d",t1,t2);
	for(i=3;i<=n;i++)
	{
		printf("%d",x);
		t1=t2;
		t2=x;
		x=t1+t2;
	}
	return 0;
}
