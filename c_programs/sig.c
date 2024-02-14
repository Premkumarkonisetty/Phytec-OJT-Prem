#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sigint_handler(int signum)
{
	printf("\nHey, I got SIGINT: %d\n",signum);
	signal(SIGINT,SIG_IGN);
	signal(SIGINT,SIG_DFL);
}
void sigquit_handler(int signum)
{
	printf("\nHey, I got SIGQUIT: %d\n\n",signum);
	signal(SIGQUIT,SIG_IGN);
	signal(SIGQUIT,SIG_DFL);
}
void sigtstp_handler(int signum)
{
	printf("\nHey, I got SIGTSTP: %d\n\n",signum);
	signal(SIGTSTP,SIG_IGN);
	signal(SIGTSTP,SIG_DFL);
}
void sigkill_handler(int signum)
{
	printf("\nHey, I got SIGKILL: %d\n\n",signum);
	signal(SIGKILL,SIG_IGN);
	signal(SIGKILL,SIG_DFL);
}
void sigstop_handler(int signum)
{
	printf("\nHey, I got SIGSTOP: %d\n\n",signum);
	signal(SIGSTOP,SIG_IGN);
	signal(SIGSTOP,SIG_DFL);
}
void sigfpe_handler(int signum)
{
	printf("\nHey, I got SIGFPE: %d\n\n",signum);
	signal(SIGFPE,SIG_IGN);
	signal(SIGFPE,SIG_DFL);
}
int main()
{
	signal(SIGINT,sigint_handler);
	signal(SIGQUIT,sigint_handler);
	signal(SIGTSTP,sigint_handler);
	signal(SIGKILL,sigint_handler);
	signal(SIGSTOP,sigint_handler);
	signal(SIGFPE,sigint_handler);
	while(1)
{
	printf("I am in an infinite loop!\n");
	sleep(1);
}
return 0;
}
