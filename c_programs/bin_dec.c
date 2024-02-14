#include<stdio.h>
int main()
{
	int x,n,r=1,sum=0;
	printf("Enter the binary number:");
	scanf("%d",&n);
	while(n>0)
	{
		x=n%10;
		n=n/10;
		if(x==1)
			sum=sum+r;
			r=r*2;
	}
		printf("%d",sum);
		return 0;
}

