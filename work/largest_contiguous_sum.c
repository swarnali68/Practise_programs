#include <stdio.h>

int large_sum(int a[], int n)
{
	int i = 0, j;
	int seqStart;
	int seqEnd;
	int maxsum = 0;
	int thisSum = 0;

	for(j=0; j<n; j++)
	{
		thisSum = thisSum + a[j];

		if (thisSum > maxsum)
		{
			maxsum = thisSum;
			seqStart = i;
			seqEnd = j;
		}

		if(thisSum < 0)
		{
			thisSum = 0;
			i = j+1;
		}
	} 
	printf("Start = %d,\t End = %d\n", seqStart, seqEnd);

	return maxsum;
}

int main()
{
	int array[] = {-1, 3, 4, -9, 8, 11, -2, -1};
	int size = sizeof(array)/sizeof(array[0]);

	int sum = large_sum(array, size);

	printf("Largest sum is: %d\n", sum);
	
	return 0;
}
