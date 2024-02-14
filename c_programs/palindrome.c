#include<stdio.h>
int main()
{
	int n,r,sum=0,temp;
	printf("Enter a number:");
	scanf("%d",&n);
	temp=n;
	while(n>0)
	{
		r=n%10;
		sum=(sum*10)+r;
		n=n/10;
	}
	if(temp==sum)
		printf("Is a palindrome");
	else
		printf("Is not a palindrome");
	return 0;
}
