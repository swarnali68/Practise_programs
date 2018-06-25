#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>

void* square_root(void* sp)
{
	int i;
	double val = 0.0;

	double *sqr = (double *) malloc (100 * sizeof(double));

	for(i = 0; i <= 99; i++)
	{
		sqr[i] = sqrt(val);
		val++;
	}

	return sqr; 
}

int main()
{
	pthread_t tid;
	void *exit_status;
	double* thread_status;
	int i;

	pthread_create(&tid, NULL, square_root, NULL);

	printf("*******Square root function executing*********\n");

	pthread_join(tid, &exit_status);
	thread_status = (double *) exit_status;

	for(i = 0; i <= 99; i++)
	{	
		printf("square root of %d is: %lf\n", i,thread_status[i]);
	}

	return 0;
}
