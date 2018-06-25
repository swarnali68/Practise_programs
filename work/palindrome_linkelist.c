#include <stdio.h>
#include "stack_lib.h"

int check_palindrome(Node* head, Node** head_ptr)
{

	if(!head)
		return -1;

	int isp = check_palindrome(head->next, head_ptr);

	if(isp == 1)
		return 1;

	if(head->data == (*head_ptr)->data)
	{
		(*head_ptr) = (*head_ptr)->next;
		isp =  0;
	}
	else
	{
		isp = 1;
	}
	return isp;
}

int main()
{
	Node* head = NULL;

	createList(&head, 1);
	createList(&head, 2);
	createList(&head, 3);
	createList(&head, 2);
	createList(&head, 1);
	createList(&head, 5);

	printList(head);

	if(check_palindrome(head, &head) == 0)
		printf("Palindrome\n");
	else
		printf("Not palindrome\n");

	return 0;
}

