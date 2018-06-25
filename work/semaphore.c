#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;
int shared_data = 4234567;

void* thread_fun(void* arg)
{
	sem_wait(&sem);
	while (shared_data > 0)
	{
		shared_data--;
	}
	sem_post(&sem);
}

int main()
{
	pthread_t tid;

	sem_init(&sem, 1, 1);

	pthread_create(&tid, NULL, thread_fun, NULL);

	sem_wait(&sem);
	
	printf("shared_data = %d\n", shared_data);

	sem_post(&sem);

	pthread_join(tid, NULL);

	sem_destroy(&sem);
	
	return 0;	
}
