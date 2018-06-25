#include<iostream>
#include<limits.h>

using namespace std;

int min_jump(int a[], int n)
{
	int i;
	int j;
	int min_jump[n];
	
	min_jump[0] = 0;

	for(i=1; i<n; i++)
	{
		min_jump[i] = INT_MAX;
		for(j=0; j<=i; j++)
		{
			if(j+a[j] >= i)
			{
				min_jump[i] = min(min_jump[j]+1, min_jump[i]);
			}
		}
	}
	return min_jump[n-1];
}

int main()
{
	int a[]= {2,1,3,2,3,4,5,1,2,8};

	int n = sizeof(a)/sizeof(a[0]);

	cout<<min_jump(a,n)<<endl;

	return 0;
}
