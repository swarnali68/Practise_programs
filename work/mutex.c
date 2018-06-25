#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t 	lock;
int 			shared_data;

void* thread_fun(void* arg)
{
	int i = 0;

	pthread_mutex_lock(&lock);

	for(i = 0; i < 1024*1024; i++)
	{
		shared_data++;
	}	
	pthread_mutex_unlock(&lock);
}
int main()
{
	pthread_t tid;
	int i;

	pthread_mutex_init(&lock, NULL);

	pthread_create(&tid, NULL, thread_fun, NULL);

	for(i = 0; i < 10; i++)
	{
		sleep(1);

		pthread_mutex_lock(&lock);

		printf("shared_data: %d\n", shared_data);

		pthread_mutex_unlock(&lock);
	}

	pthread_join(tid, NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}
