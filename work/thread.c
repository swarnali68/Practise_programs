#include<stdio.h>
#include<pthread.h>

void* thread_fun(void* arg)
{
	printf("Inside thread function: %s\n", (char *)arg);
}

int main()
{
	pthread_t tid1, tid2;
	char* msg1 = "Message 1";
	char* msg2 = "Message 2";

	printf("Before creating thread\n");	
	pthread_create(&tid1, NULL, thread_fun, msg1);
	pthread_create(&tid2, NULL, thread_fun, msg2);
	printf("After creating thread\n");

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}
