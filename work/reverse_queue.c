#include<stdio.h>
#include "queue.h"
#include "stack_new.h"

void reverse(Queue *q)
{
	Stack s;
	s.top = NULL;

	int temp;

	while(q->front != NULL)
	{
		temp = dequeue(q);
		push(&s, temp);
	}

	while(s.top != NULL)
	{
		temp = pop(&s);
		enqueue(q, temp);
	}		
}

void reverse_n_node(Queue *q, int n)
{
	Stack s;
	int i = 0;
	int val = 0;
	int size  = 0;

	s.top = NULL;
	
	while (i < n)
	{
		val = dequeue(q);
		push(&s, val);
		i++;
	}

	i = 0;

	while (i < n)
	{
		val = pop (&s);
		enqueue(q, val);
		i++;
	}

	size = q->size - n;

	while(size--)
	{
		val = dequeue(q);
		enqueue(q, val);
	}	
}

void printQueue(Queue *q)
{
	Node* temp = q->front;

	while (temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next; 
	}
	printf("\n");
}

int main()
{
	Queue q;
	int n = 0;

	q.front = NULL;
	q.rear = NULL;
	q.size = 0;

	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);

	reverse(&q);

	printQueue(&q);

	printf("Enter the n node: ");
	scanf("%d", &n);

	if ((n < 0 ) || (n > q.size))
	{
		printf("Idiot , Enter proper number!!\n");
		return 0;
	}

	reverse_n_node(&q, n);

	printQueue(&q);

	return 0;
}
