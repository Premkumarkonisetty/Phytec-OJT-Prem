#include<stdio.h>
int main()
{
	int i,j,row;
	printf("Enter no of rows: ");
	scanf("%d",&row);
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%c",(j+64));
		}
		printf("\n");
	}
}
