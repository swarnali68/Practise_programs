#include <stdio.h>

void merge(int a[], int l, int m, int r)
{
	int n1, n2, i , j , k;

	n1 = m - l + 1;
	n2 = r - m;

	int left[n1], right[n2];

	for(i = 0; i < n1; i ++)
		left[i] = a[l + i];

	for(j = 0; j < n2; j++)
		right[j] = a[m + 1 + j];

	i = 0;
	j = 0;
	k = l; 
	
	while (i < n1 && j < n2)
	{
		if(left[i] < right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}	
		k++;	
	}

	while (i < n1)
	{
		a[k] = left[i];
		i++;
		k++;
	}

	while(j < n2)
	{
		a[k] = right[j];
		j++;
		k++;
	}
}

void merge_sort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		merge_sort(a, l, m);
		merge_sort(a, m+1, r);
	
		merge(a, l, m, r);
	}
}

void printArray(int a[], int n)
{
	int i = 0;

	for(i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}
int main()
{
	int array[] = {17, 13, 21, 19, 1, 4, 11, 77};

	int n = sizeof(array)/sizeof(array[0]);

	printf("Before Sorting: ");
	printArray(array, n);

	merge_sort(array, 0, n-1);

	printf("After Sorting: ");
	printArray(array, n);

	return 0;
}

