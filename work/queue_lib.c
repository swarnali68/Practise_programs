#include "queue_lib.h"
#include <stdlib.h>


int dequeu(Node** front, Node** rear)
{
	int data;

	if(*front != NULL)
	{
		Node* tmp;
		tmp = *front;
		data = (*front)->data;
		if(*front == *rear)
			*front = *rear = NULL;
		else
			*front = (*front)->next;
		free(tmp);
		return data;	
	}
}

void enqueu(Node** front, Node** rear, int data)
{
	Node* tmp;

	tmp = (Node*) malloc (sizeof (Node*));

	tmp->data = data;
	tmp->next = NULL;

	if (*rear == NULL)
	{
		*rear = *front = tmp;
	}
	else
	{
		(*rear)->next = tmp;
		*rear = (*rear)->next;
	}
}

void printqueu(Node* front)
{
	while(front != NULL)
	{
		printf("%d\t", front->data);
		front = front->next;
	}
}


/*int main()
{
	Node* front = NULL;
	Node* rear = NULL;

	enqueu(&front, &rear, 1);
	enqueu(&front, &rear, 2);
	enqueu(&front, &rear, 3);

	dequeu(&front, &rear);
	
	printqueu(front);

	return 0;
}*/
