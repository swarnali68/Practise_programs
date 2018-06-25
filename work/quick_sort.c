#include<stdio.h>

void swap(int *xp, int *yp)
{
	int t;
		
	t = *xp;
	*xp = *yp;
	*yp = t;
}

int partition(int a[], int low, int high)
{
	int pivot;
	int j;
	int i;

	pivot = a[high];
	i = low - 1;

	for(j = low; j < high; j++)	
	{
		if(a[j] < pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[high]);

	return(i + 1);
}

void quickSort(int a[], int low, int high)
{
	if(low < high)
	{
		int p = partition(a, low, high);

		quickSort(a, low, p - 1);
		quickSort(a, p + 1, high);
	}
}

void printArray(int a[], int n)
{
	int i;

	for(i = 0; i < n; i++)
		printf("%d \t", a[i]);

	printf("\n");
}

int main()
{
	int array[] = {19, 11, 23, 2, 5, 23, 29, 18, 1};
//	int array[] = {1, 10, 2, 3, 5 , 10, 99, 19, 20};

	int n = sizeof(array)/sizeof(array[0]);

	printf("Before Sorting: ");
	printArray(array, n);

	quickSort(array, 0, n-1);

	printf("After Sorting: ");
	printArray(array, n);

	return 0;
}
