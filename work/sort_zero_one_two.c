#include <stdio.h>
#include "stack_lib.h"

void sortList(Node* head)
{
	Node* temp = head;
	int array[3] = {0};
	int i = 0;

	while(temp != NULL)
	{
		array[temp->data]++;
		temp = temp->next;
	}

	temp = head;
	
	while(temp != NULL)
	{
		if(array[i] == 0)
		{
			i++;
		}
		else
		{
			temp->data = i;				
			array[i]--;
		
			temp = temp->next;	
		}
	}
}

int main()
{
	Node* head = NULL;

	createList(&head, 2);
	createList(&head, 0);
	createList(&head, 2);
	createList(&head, 1);
	createList(&head, 0);

	printList(head);

	sortList(head);

	printf("After Sorting:\n");
	printList(head);

	return 0;
}
