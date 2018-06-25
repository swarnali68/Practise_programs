#include"stack_lib.h"


void createList(Node** headptr,int data)
{
        Node* temp = NULL;
	Node* ptr = NULL;

        temp = (Node*)malloc (sizeof(Node));
        temp->data = data;
        temp->next = NULL;
        if(!(*headptr))
        {
                *headptr = temp;
        }
        else
        {
		ptr = *headptr;
		while(ptr->next)
		{
			ptr = ptr->next;
		}	
                ptr->next = temp;
        }

}
char pop(Node** head)
{
	Node* temp = NULL;
	char ch = '\0';

	if(head != NULL)
	{
		temp = *head;
		ch = (*head)->data;
		*head = (*head)->next;
		free(temp);
		return ch;
	}	
}
void push(Node** headptr,char data)
{
        Node* temp = NULL;

	temp = (Node*)malloc (sizeof(Node));
        temp->data = data;
	if(!(*headptr))
	{
		temp->next = NULL;
		*headptr = temp;	
	}
	else
	{
                temp->next = *headptr;
		*headptr = temp;	
	}

}

void printList(Node* head)
{
	while(head)
	{
		printf("%c\n",head->data);
		head = head->next;
	}
}
/*int main()
{
	Node* head = NULL;
	
	createList(&head, 10);
	createList(&head, 20);
	printList(head);
	
	return 0;
}*/
