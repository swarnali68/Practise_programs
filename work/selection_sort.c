#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp;
	
	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selection_sort(int a[], int n)
{
	int i = 0;
	int small_index = 0;
	int j = 0;

	for(i = 0; i < n; i++)
	{
		small_index = i;
		
		for(j = i+1; j < n; j++)
		{
			if(a[j] < a[small_index])
				swap(&a[j], &a[small_index]);
		}
	}
}

void printArray(int a[], int n)
{
	int i = 0;

	while(i < n)		
	{
		printf("%d\t", a[i++]);
	}
	printf("\n"); 
}

int main()
{
	int array[] = {11, 54, 4, 13, 1};
	int n = sizeof(array)/sizeof(array[0]);

	selection_sort(array, n);
	
	printf("Sorted Array: \n");
	printArray(array, n);
	
	return 0;
}
