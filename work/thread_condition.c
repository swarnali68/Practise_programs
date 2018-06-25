#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
pthread_cond_t  cond;


int shared_data = 428798;

void* thread_fun(void* arg)
{
	pthread_mutex_lock(&lock);
	while (shared_data > 0)
	{
		shared_data--;
	}
	pthread_mutex_unlock(&lock);
	
	pthread_cond_signal(&cond);
}

int main()
{
	pthread_t tid;

	pthread_create(&tid, NULL, thread_fun, NULL);

	pthread_mutex_init(&lock, NULL);
	pthread_cond_init(&cond, NULL);

//	pthread_join(tid, NULL);
	
//	sleep(1);
	pthread_mutex_lock(&lock);
	
	while(shared_data != 0)

	pthread_cond_wait(&cond, &lock);

	printf("Shared_data = %d\n", shared_data);

	pthread_mutex_unlock(&lock);

	pthread_join(tid, NULL);

	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&lock);

	return 0;
}
