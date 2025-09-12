#include <stdio.h>
#include <unistd.h> /* contains fork prototype */
int main(void)
{
	int pid;
	printf("Hello IIITA!\n");
	printf("I am the parent process and pid is : %d .\n",getpid());
	printf("We are before fork\n");
	pid = fork();
	printf("Here we are after fork and a new child has been created\n");
	if (pid == 0)
		printf("I am the child process and pid is :%d.\n",getpid());
	else
		printf("I am the parent process and pid is: %d .\n",getpid());
}