#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void myhandler(int signum)
{
	printf("Hey, I got signal: %d\n",signum);
	for(int i=1; i<=10; i++)
	{
		printf("I am masking SIGINT for 10 seconds!\n");
		sleep(1);
	}
	printf("Done with the handler function and falling back to main() after 2 sec\n\n");
	sleep(2);
}
int main()
{
	struct sigaction newact;
	newact.sa_handler = myhandler;
	newact.sa_flags = 0;
	sigemptyset(&newact.sa_mask);
	//sigfileset(&newact.sa_mask);
	sigaction(SIGINT, &newact, NULL);
	while(1)
	{
		printf("I am main() in a infinite loop!\n");
		sleep(1);
	}
	return 0;
}
