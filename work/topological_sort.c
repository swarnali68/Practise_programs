#include <stdio.h>
#include <stdlib.h>
#include "queue_lib.h"

void topsort(int** graph, int v_count)
{
	int i = 0;
	int j = 0;
	int count = 0;
	int val = 0;
	int indegree = 0;
	int *a = NULL;;
	Node* front = NULL;
	Node* rear = NULL;

	a = (int *) calloc (v_count,sizeof(int));
	
	while(count < v_count)	
	{
	for(i = 0; i < v_count; i++)
	{
		if (a[i] > 0)
			continue;

		indegree = 0;
		for(j = 0; j < v_count; j++)
		{
			if (graph[j][i] != 0)
			{
				indegree = 1;
				break;
			}	
		}
		if ((indegree == 0) && (a[i] == 0))
		{
			a[i] = i + 1;
			enqueu(&front, &rear, i+1);
		}	
	}
	if (front == NULL)
		break;

	val = dequeu(&front, &rear);
	printf("%d\t", val);

	j = val - 1;

	for(i = 0; i < v_count; i++)
	{
		if(graph[j][i] != 0)
		{
			graph[j][i]--;
		}	
	}
	count++;
	}

	if (count != v_count)
	{
		printf("cycle detected");
	}
	printf("\n");
}

int main()
{
	int **graph = NULL;
	int vertex_count = 0;
	int i = 0;
	int j = 0;
	int val = 0;
	char ch = ' ';

	FILE* fp;

	fp = fopen("file.txt", "r");
	if (fp == NULL)
	{
		printf("File Error");
		return -1;
	}

	fscanf(fp, "%d", &vertex_count);	

	graph = (int **) malloc (sizeof(int *) * vertex_count);

	for(i = 0; i < vertex_count; i++)
	{
		graph[i] = (int *) malloc (sizeof(int) * vertex_count);
	}


	for(i = 0; i < vertex_count; i++)
	{
		for(j = 0; j < vertex_count; j++)
		{
			ch = fgetc(fp);
			fscanf(fp, "%d", &val);	
			graph[i][j] = val;	
		}
	}

	topsort(graph, vertex_count);

	return 0;
}
