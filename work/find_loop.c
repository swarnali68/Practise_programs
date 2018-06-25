#include "stack_lib.h"

void break_loop(Node* , Node* );
void break_cir_loop(Node* , Node* );

void find_loop(Node* head)
{
	Node* fast_ptr = NULL;
	Node* slow_ptr = NULL;

	fast_ptr = slow_ptr = head;

	while((fast_ptr != NULL) && (fast_ptr->next != NULL))
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;

		if(fast_ptr == slow_ptr)
		{
			if(fast_ptr == head)
				break_cir_loop(slow_ptr, head);
			else
				break_loop(slow_ptr, head);
		}
	}
	
}
void break_cir_loop(Node* ptr, Node* head_ptr)
{
	while(ptr->next != head_ptr)
	{	
		ptr = ptr->next;
	}
	ptr->next = NULL;
}
void break_loop(Node* ptr, Node* head_ptr)
{
	Node* head1 = head_ptr;
	Node* head2 = ptr;

	while(head1)
	{
		head2 = ptr; 
		while(head1->next != head2->next)
		{
			head2 = head2->next;
			
			if(head2->next == ptr)
				break;	
		}
		if(head1->next == head2->next)
			break;
	
		head1 = head1->next;
	}
	head2->next = NULL;	
}

int main()
{
	Node* head = NULL;
	Node* ptr = NULL;
	Node* ptr2 = NULL;
	int i =1;
	int n = 0;
	int pos = 0;

	/*createList(&head, 1);
	createList(&head, 2);
	createList(&head, 3);
	createList(&head, 4);
	createList(&head, 5);
	createList(&head, 6);
	createList(&head, 7);

	head->next->next->next->next->next->next->next = head->next->next;*/

	printf("Enter the size of the node: ");
	scanf("%d",&n);

	printf("Enter the loop position: ");
	scanf("%d", &pos);

	if ((pos > n) || (pos <= 0) || (n <= 0))
	{ 
		printf("Idiot - Enter a valid value\n");
		return 0;
	}

	while(n--)
	{
		createList(&head, i++);
		if(i == 2)
			ptr = head;
		else
			ptr = ptr->next;
	}


	
	ptr2 = head;
	i = 1;

	while(i < pos)
	{
		ptr2 = ptr2->next;
		i++;
	}

	ptr->next =  ptr2;

	find_loop(head);

	printList(head);

	return 0;	
}
