#include <stdio.h>

void insertion_sort(int a[], int n)
{
	int key;
	int i;
	int j;

	for(i = 1; i < n-1; i++)
	{
		key = a[i];
		j = i - 1;

		while(j >=0 && a[j] > key)
		{
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;	
	}
}
void printArray(int a[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%d\t",a[i]);
	printf("\n");
}
int main()
{
	int array[] = {12, 15, 11, 9, 1, 17};
	int n = sizeof(array)/sizeof(array[0]);

	insertion_sort(array, n);

	printArray(array, n);

	return 0;
}
