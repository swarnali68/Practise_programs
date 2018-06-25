#include "stack_lib.h"

void reverse(Node** head_ptr)
{
	Node* prev = NULL;
	Node* next = NULL;
	Node* temp  = *head_ptr;

	while(temp != NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;	
	}	
	*head_ptr = prev;
}

int main()
{
	Node* head = NULL;
	createList(&head, 10);
	createList(&head, 20);
	createList(&head, 30);

	printList(head);
	printf("Reverse\n");
	reverse(&head);
	printList(head);

	return 0;
}
