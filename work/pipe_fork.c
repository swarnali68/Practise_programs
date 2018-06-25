#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

#define MSGSIZE 16

char* msg1 = "Hello World, #1";
char* msg2 = "Hello World, #2";
char* msg3 = "Hello World, #3";

int main()
{
	int fd[2];
	pid_t pid;
	char inbuff[16];

	if(pipe(fd) < 0)
	{
		printf("Failed to create pipe\n");
		return 1;
	}

	pid = fork();

	if(pid > 0)
	{
		write(fd[1], msg1, MSGSIZE);
		write(fd[1], msg2, MSGSIZE);
		write(fd[1], msg3, MSGSIZE);

		close(fd[1]);
		wait(NULL);
	}
	else
	{
		close(fd[1]);
		while(read(fd[0], inbuff, MSGSIZE) > 0)
			printf("%s\n",inbuff);
	}
	return 0;
}
