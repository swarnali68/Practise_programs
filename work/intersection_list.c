#include "stack_lib.h"

int getCount(Node* head)
{
	int count = 0;
	
	while(head != NULL)
	{
		head = head->next;
		count++;
	}
	return count;
}

int _getIntersectionNode(int count, Node* head1, Node* head2)
{
	while(count--)
	{
		head1 = head1->next;
	}

	while(head1 != NULL && head2 != NULL)
	{
		if(head1 == head2)
			return head1->data;

		head1 = head1->next;
		head2 = head2->next;
	}
	
	return -1;
}

int getIntersectionNode(Node* head1, Node* head2)
{
	int count1 = 0;
	int count2 = 0;
	int count = 0;
	Node* ptr1 = head1;
	Node* ptr2 = head2; 
	Node* head = NULL;

	count1 = getCount(head1);
	count2 = getCount(head2);
	
	if(count1 > count2)
	{
		count = count1 - count2;
	        return _getIntersectionNode(count, head1, head2);	
	}
	else
	{
		count = count2 - count1;
		return _getIntersectionNode(count, head2, head1);	
	}

}

int main()
{
	int n1 = 0;
	int n2 = 0;
	int i = 1;
	int data = 0;
	Node* head1 = NULL;
	Node* head2 = NULL;
	Node* ptr = NULL;

	printf("Enter the size of the first list: ");
	scanf("%d",&n1);

	printf("Enter the size of the second list: ");
	scanf("%d",&n2);

	while(n1--)
	{
		createList(&head1, i++);
	}

	i = 1;

	while(n2--)
	{
		createList(&head2, i++);
		if(i == 2)
			ptr = head2;
		else
			ptr = ptr->next;
	}	

	ptr->next = head1->next->next->next;

	printList(head1);
	printf("\n\n");
	printList(head2);

	data = getIntersectionNode(head1, head2);	
	printf("The intersection node is: %d\n", data);
	
	return 0;
}
