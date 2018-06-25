#include<stdio.h>
#include<stdlib.h>

int main()
{
	int fd[2];
	int fd2[2];
	int pid = -1;
	int nbytes = 0;
	char buffer[6] = "";
	char buffer2[24] = "";
	
	if(pipe(fd) < 0)
	{
		printf("Pipe could not be created\n");
		exit(1);
	}

	if(pipe(fd2) < 0)
	{
		printf("Pipe could not be created\n");
		exit(1);
	}

	pid = fork();

	if(pid < 0)
		exit(1);

	if(pid > 0)
	{
		close(fd[0]);
		printf("*******Writing to the pipe**********\n");
		write(fd[1], "Hello",6);
		write(fd[1], "World",6);
		printf("*******Finished Writing************\n");

		close(fd[1]);
		wait(NULL);

		close(fd2[1]);
		while(nbytes = read(fd2[0], buffer2, 24)> 0)
			printf("%s\n",buffer2);
		close(fd2[0]);
	}
	else
	{
		close(fd[1]);
		printf("**********Reading from the pipe*********\n");
		while(nbytes = read(fd[0], buffer, 6) > 0)
		{
			printf("nbytes = %d\n", nbytes);
			printf("%s\n", buffer);
		}
		printf("*********Finished Reading************\n");
		close(fd[0]);
		nbytes = 0;

		close(fd2[0]);
		write(fd2[1], "Finished Reading, Ack!!", 24);
		close(fd2[1]);
		
	}

	return(0);
}
