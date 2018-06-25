#include<iostream>

using namespace std;

void minimum_jump_path(int a[], int n)
{
	int i = 0;
	int j = 0;
	int index=0;
	int max=0;
	int max_index = 0;
	int count = 0;
	
	while(i < n-1)
	{
		index = i + a[i];
		if(index >= n-1)
		{
			count++;
			break;
		}	
		max = a[i+1];
		max_index = i+1;
		for(j=i+2; j<=index; j++)
		{
			if(j >= n)
			{
				max_index = j;
				break;
			}
			if(a[j] > max)
			{
				//if(a[j] > n)
				//	break;
				max = a[j];
				max_index = j;
			}
		}
		i = max_index;
		count++;
	}
	cout<<count<<endl;
}

int main()
{
	//int a[8] = {1,3,5,8,9,2,6,7};
	//int a[] = {2,3,1,1,2,4,2,0,1,1};
	
	int a[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
	int n = sizeof(a)/sizeof(a[0]);

	minimum_jump_path(a,n);

	return 0;
}
