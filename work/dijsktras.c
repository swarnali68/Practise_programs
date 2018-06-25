#include<stdio.h>
#include<limits.h>

#define V 9

int min_element(int *dist, int* sptset)
{
	int min = INT_MAX;
	int i;
	int min_index = -1;

	for(i = 0; i < V; i++)
	{
		if((dist[i] < min) && (sptset[i] != 1))
		{
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

void printSolution(int *dist)
{
	int i;

	for(i = 0; i < V; i++) 
	{
		printf("(%d,%d)\t", i, dist[i]);
	}
	printf("\n");
}

void dijsktras(int graph[V][V], int src)
{
	int dist[V];
	int sptset[V];
	int i;
	int count;
	int v;
	int u;

	for(i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		sptset[i] = 0;
	}

	dist[src] = src;

	for(count=0; count < V; count++)
	{
		u = min_element(dist, sptset);

		if(u < 0)
			return;

		sptset[u] = 1;

		for(v = 0; v < V; v++)
		{
			if(!sptset[v] && graph[u][v] && (dist[u] + graph[u][v] < dist[v]))
			{
				dist[v] = dist[u] + graph[u][v];
			}	
		}	
	}

	printSolution(dist);
}

int main()
{
	int graph[V][V] = {0, 4, 0, 0, 0, 0, 0, 8, 0,
			   4, 0, 8, 0, 0, 0, 0, 11, 0,
			   0, 0, 0, 7, 0, 4, 0, 0, 2,
			   0, 0, 7, 0, 9, 14, 0, 0, 0,
			   0, 0, 0, 9, 0, 10, 0, 0, 0,
			   0, 0, 4, 14, 10, 0, 2, 0, 0,
			   0, 0, 0, 0, 0, 2, 0 ,1, 6,
			   8, 11, 0, 0, 0, 0, 1, 0, 7,
			   0, 0, 2, 0, 0, 0, 6, 7, 0};

	dijsktras(graph, 0);
	return 0;
}
