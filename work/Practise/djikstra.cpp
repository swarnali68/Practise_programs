#include<iostream>
#include<limits.h>

#define V 9 

using namespace std;

int find_min(int a[], int a2[])
{
	int min = INT_MAX;
	int min_index = -1;
	for(int i=0 ; i< V; i++)
	{
		if((a2[i] == 0) && (a[i] < min))
		{
			min = a[i];
			min_index = i;
		}
	}
	a2[min_index] = 1;
	return min_index;
}

void dijkshtra(int graph[][V])
{
	int a[V];
	int a2[V];
	int i = 0;
	int j;
	int row = 0;

	for(i=0; i<V; i++)
	{
		a[i] = INT_MAX;
		a2[i] = 0;
	}
	a[0] = 0;

	for(i=0; i<V; i++)
	{

	row = find_min(a,a2);

	if(row < -1)
		break;

	for(j=0; j<V; j++)
	{
		if((a[row] + graph[row][j] < a[j]) && (graph[row][j] != 0))
		{
			a[j] = a[row] + graph[row][j];
		}
	}
	}
	for(i=0; i<V; i++)
	{
		cout<<"("<<i<<","<<a[i]<<")"<<"\t";
	}
}

int main()
{
	/*int graph[V][V] = {0,5,0,0,0,0,0,
			   0,0,4,0,5,0,0,
			   0,0,0,6,0,0,0,
			   0,0,0,0,0,0,0,
			   0,0,0,0,0,8,1,
			   0,0,0,9,0,0,0,
			   0,0,0,0,0,2,0};*/

	int graph[V][V] = {0, 4, 0, 0, 0, 0, 0, 8, 0,
                           4, 0, 8, 0, 0, 0, 0, 11, 0,
                           0, 0, 0, 7, 0, 4, 0, 0, 2,
                           0, 0, 7, 0, 9, 14, 0, 0, 0,
                           0, 0, 0, 9, 0, 10, 0, 0, 0,
                           0, 0, 4, 14, 10, 0, 2, 0, 0,
                           0, 0, 0, 0, 0, 2, 0 ,1, 6,
                           8, 11, 0, 0, 0, 0, 1, 0, 7,
                           0, 0, 2, 0, 0, 0, 6, 7, 0};


	dijkshtra(graph);
	return 0;
}
