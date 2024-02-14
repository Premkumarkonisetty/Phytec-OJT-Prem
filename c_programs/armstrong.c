#include<stdio.h>
int main()
{
	int n,r,rem;
	printf("Enter the number:");
	scanf("%d",&n);
	while(n)
	{
		r=n%10;
		r=r+(rem);
		n=n/10;
	}
	if(r==n)
	{
		printf("Is an Armstrong number");
	}
	else
	{
		printf("Not an Armstrong number");
	}
}
