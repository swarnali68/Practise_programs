#include "stack_lib.h"

void swap_nodes(Node** head)
{
	Node* ptr1 = *head;
	Node* ptr2 = NULL;
	Node* ptr3 = NULL;

	int i = 1;
	
	while(ptr1->next != NULL)
	{
		ptr2 = ptr1->next;
		ptr1->next = ptr2->next;
		ptr2->next = ptr1;
		if( i == 1)
		{
			*head = ptr2;
			ptr3 = ptr1;
		}
		else
		{
			ptr3->next = ptr2;
			ptr3 = ptr1;
		}
		i++;
		if(ptr1->next == NULL)
			break;
		ptr1 = ptr1->next; 
	}
	//printList(head);
}

int main()
{
	Node* head = NULL;
	int n;
	int i = 1;

	printf("Enter the size of the list:");
	scanf("%d",&n);

	while(i <= n)
	{
		createList(&head, i++);
	}

	swap_nodes(&head);

	printList(head);
	
	return 0;
} 
