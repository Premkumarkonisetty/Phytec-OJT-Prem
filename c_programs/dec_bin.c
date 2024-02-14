#include<stdio.h>
int main()
{
	int a[10];
	int i=0,n,j;
	printf("Enter the decimal number:");
	scanf("%d",&n);
	while(n>0){
		a[i]=n%2;
		n=n/2;
		i++;
	}
		for(j=i-1;j>=0;j--)
		{
			printf("%d",a[j]);
		}
}
