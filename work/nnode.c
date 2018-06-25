#include"stack_lib.h"

void find_nnode(Node* head, int n)
{
	Node* ptr1 = head;
	Node* ptr2 = head;
	int i = 1;

	while((i < n) && (ptr2->next != NULL))
	{
		ptr2 = ptr2->next;
		i++;
	}
	
	if(((ptr2->next == NULL) && (i != n)) || ((n == 0) || ( n < 0)))
	{
		printf("Out of range\n");
		return;
	}

	while(ptr2->next != NULL)
	{
		ptr1 = ptr1->next;
	  	ptr2 = ptr2->next;	
	}
	
	printf("Nth node is: %d\n", ptr1->data);
}

int main()
{
	Node* head = NULL;
	int n = 1;
	
	createList(&head, 1);
	createList(&head, 2);
	createList(&head, 3);
	createList(&head, 4);
	createList(&head, 5);
        createList(&head, 6);
        createList(&head, 7);
	

	printList(head);

	printf("Enter the nth node from last\n");
	scanf("%d",&n);

	printf("%d\n\n", n);

	find_nnode(head, n);

	return 0;
}
