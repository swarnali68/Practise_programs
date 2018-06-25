#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int forkexample()
{
	if(fork() == 0)
		printf("Child Process\n");
	else
		printf("Parent Process\n");
}

int main()
{
	forkexample();
	return 0;
}
