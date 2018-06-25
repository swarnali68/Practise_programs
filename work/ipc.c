#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		printf("Child process\n");
	//	printf("Child Pid: %d\n", getpid());
	//	printf("Parent Pid: %d\n", getppid());
	}
	else
	{
		wait(NULL);
		printf("Parent Process\n");
	//	printf("Parent Pid: %d\n",getpid());
	//	printf("Child Pid: %d\n", pid);
	}
	return 0;
}
