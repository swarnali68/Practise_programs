#include<iostream>

#define V 5

using namespace std;

void topological_sort(int graph[][V])
{
	int i= 0;
	int j = 0;
	int flag = 0;
	int val = j;
	int v = V;
	int a[V] = {0};

	while(v--)
	{
	for(j=0; j < V; j++)
	{
		if(a[j])
			continue;

		flag = 0;
		for(i=0; i<V; i++)
		{
			if(graph[i][j] != 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			a[j] = 1;
			val = j;
			break;
		}
	}
	if(a[val])
	{
		cout<<"cycle found";
		return;
	}
	cout<<val+1<<"\t";
	for(j=0; j<V; j++)
	{
		graph[val][j] = 0;
	}
	}
	cout<<endl;	
}
int main()
{
	/*int graph[V][V] = {0, 1, 0, 0, 1,
			   0, 0, 0, 0, 1,
			   0, 1, 0, 0, 0,
			   0, 1, 0, 0, 0,
			   0, 0, 1, 0, 0};*/

	int graph[V][V] = {0, 1, 0, 1, 0,
			   0, 0, 0, 0, 1,
			   0, 1, 0, 0, 0,
			   0, 1, 0, 0, 0,
			   0, 0, 1, 0, 0};


	topological_sort(graph);

	return 0; 
}
