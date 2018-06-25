#include <stdio.h>
#include<unistd.h>
#include <pthread.h>

void* thread_fun(void* i)
{
	int counter;

	int *thread_count = (int *) i;

	//for(counter = 0; counter < 5; counter++)
		printf("Hello World: Thread %d\n", *thread_count);
}

int main()
{
	pthread_t tid[10];
	int n;
	int i;
	int t[10];

	printf("Enter the number of threads: ");
	scanf("%d",&n);

	for(i=1; i <= n; i++)
	{
		//t[i] = i;
		//pthread_create(&tid[i], NULL, thread_fun, &t[i]);
		pthread_create(&tid[i], NULL, thread_fun, &i);
                //sleep(2);
	} 

/*	for(i = 1; i <= n ; i++)
	{
		pthread_join(tid[i], NULL);
	}*/

	pthread_exit(NULL);

	return 0;
}
