#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}Node;

void enqueu(Node** front, Node** rear, int data)
{
	Node* tmp = (Node*) malloc (sizeof(struct node));

	tmp->data = data;
	tmp->next = NULL;
	
	if(*front == NULL)
	{
		*front = *rear = tmp;
		(*rear)->next = *front;
	}
	else
	{
		(*rear)->next = tmp;
		(*rear) = (*rear)->next;
		tmp->next = *front;
	}
}

void dequeu(Node** front, Node** rear)
{
	Node* tmp;

	if(*front != NULL)
	{
		tmp = *front;
		if(*front == *rear)
		{
			*front = *rear = NULL;
		}
		else
		{
			*front = (*front)->next;
			(*rear)->next = *front;
		}
		free(tmp);
	}
}

void printqueue(Node* front, Node* rear)
{
	Node* tmp = front;
	do
	{
		printf("%d\t", tmp->data);
		tmp = tmp->next;
	}while(tmp != front);

	printf("\n");
}

int main()
{
	Node* front = NULL;
	Node* rear = NULL;

	enqueu(&front, &rear, 1);
	enqueu(&front, &rear, 2);
	enqueu(&front, &rear, 3);

	printqueue(front, rear);

	dequeu(&front, &rear);

	printqueue(front, rear);

	
	return 0;
}
