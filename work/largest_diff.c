#include <stdio.h>

//int max_diff = 1;

int max_diff(int a[], int n)
{
	int i;
	int diff;	
	int large = a[n-1];
	int max_diff = 0;

	for(i = n - 1; i >= 0; i--)
	{
		if (a[i] > large)
			large = a[i];

		diff = large - a[i];
		if (diff > max_diff)
			max_diff = diff; 
	}
	return max_diff;
}

int main()
{
	int a[10] = {10, 6, 5 , 4, 12, 2, 3, 0, 4, 7};
	int diff;

	diff = max_diff(a, 10);

	printf("Max diff is : %d\n", diff);

	return 0;
}
