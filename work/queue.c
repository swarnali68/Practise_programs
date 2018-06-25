
#include<stdio.h>
#include<stdlib.h>
#include"queue.h"


int dequeue(Queue *q)
{
	Node* temp = NULL;
	int data = 0;


	if(q->front != NULL)
	{
		data = q->front->data;
		temp = q->front;
		if (q->front == q->rear)
		{
			q->front = q->rear = NULL;
		}
		else
		{
			q->front = q->front->next;
		}
		temp->next = NULL;
		free (temp);
		q->size--;
	}
	else
	{
		data = -1;
	}

	return data;
}

void enqueue(Queue* q, int data)
{
	Node* temp;

	temp = (Node*)malloc (sizeof(Node) * 1);
	temp->data = data;
	temp->next = NULL;

	if(q->front == NULL)
	{
		q->front = temp;
		q->rear = temp;
		q->size++;
	}
	else
	{
		q->rear->next = temp;
		q->rear = q->rear->next;
		q->size++;
	}
	
}


/*int main()
{
	Queue q;
	int data;

	q.front = q.rear = NULL;
	
	enqueu(&q,10);	
	
	data = dequeue(&q);

	printf("%d\n",data);

	return 0;
}*/
