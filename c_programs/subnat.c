#include<stdio.h>
int main()
{
	int i,n,sum=0;
	printf("Enter positive integer:");
	scanf("%d",&n);
	if(n<=0){
		printf("Please enter a positive integer: ");
		return 1;
	}
	for(i=1;i<=n;i++)
	{
		printf("Sum of natural numbers %d is: %d\n",n,sum);
		sum += i;
	}
	return 0;
}
