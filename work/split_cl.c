#include "stack_lib.h"

Node* split_circularList(Node* head)
{
	Node* fast_ptr = head;
	Node* slow_ptr = head;
	Node* head2 = NULL;

	if(head == NULL)
		return NULL;

	while((fast_ptr->next != head) && (fast_ptr->next->next != head))
	{
		if((fast_ptr == NULL) && (fast_ptr->next == NULL))
		{
			printf("Not Circular Linked List\n");
			return NULL;	
		}
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}
	head2 = slow_ptr->next;
	
	if(fast_ptr->next == head)
		fast_ptr->next = NULL;
	else
		fast_ptr->next->next = NULL;

	slow_ptr->next = NULL;

	return head2;

}

int main()
{
	int i = 1;
	Node* head = NULL;
	Node* head2 = NULL;
	Node* ptr = NULL;
	int n = 0;

	printf("Enter size of the list:");
	scanf("%d", &n);

	while(n--)
	{
		createList(&head, i++);
		if(i == 2)
			ptr = head;
		else
			ptr = ptr->next;	
	}

	ptr->next = head;

 	head2 = split_circularList(head);

	printf("1st List\n");
	printList(head);
	printf("2nd List\n");
	printList(head2);

	return 0;
}

