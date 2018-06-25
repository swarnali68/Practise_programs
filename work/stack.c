#include<stdio.h>
#include<stdlib.h>

struct node
{
	 int data;
	 struct node* next;
};

void push (struct node** headptr, int data)
{
	struct node* node = (struct node*) malloc (sizeof(struct node));
	if (node == NULL)
	{
		 printf("\nMemory Allocation failed");
		 return;
	}
	node->data = data;
	node->next = *headptr;
	*headptr = node;
}

int pop(struct node** headptr)
{
	 struct node* tmpNode = NULL;
 	 int data = 0;

	 data = (*headptr)->data;
	 tmpNode = *headptr;
	 *headptr = (*headptr)->next;

	 free (tmpNode);
	 tmpNode = NULL;

	 return data;
}

void display(struct node *tmp)
{
	 while (tmp != NULL)
	 {
		  printf("\nPushed: %d", tmp->data);
		  tmp = tmp->next;
	 }

}

void display_recursion(struct node* tmp)
{
	 printf("\nPushed: %d", tmp->data);

	 if (tmp->next == NULL)
		  return;
	 display_recursion(tmp->next);
	 /* reverse data
		 printf("\nPushed: %d", tmp->data);
	  */
}

void reverse (struct node** headptr)
{
	 struct node* prev = NULL;
	 struct node* next = NULL;

	 while (*headptr != NULL)
	 {
		  next = (*headptr)->next;
		  (*headptr)->next = prev;
		  prev = *headptr;
		  *headptr = next;
	 }
	 *headptr = prev;
}

void middle_element(struct node* head)
{
	 struct node* fast_ptr = head;
	 struct node* slow_ptr = head;

	 if (head == NULL)
	 {
		  printf("\n No data found");
		  return;
	 }
	 while((fast_ptr != NULL) && (fast_ptr->next != NULL))
	 {
		  fast_ptr = fast_ptr->next->next;
		  slow_ptr = slow_ptr->next; 
	 }

	 printf("\nMiddle Element is: %d", slow_ptr->data);
}

void remove_loop(struct node* loop_node, struct node* head)
{
	 struct node* ptr1 = NULL;
	 struct node* ptr2 = NULL;

	 ptr1 = head;

	 while(1)
	 {
		  ptr2 =  loop_node;

		  while ((ptr2->next != loop_node) && (ptr2->next != ptr1))
		  {
				ptr2 = ptr2->next;
		  }

		  if(ptr2->next == ptr1)
				break;

		  ptr1 = ptr1->next;
	 }
	 printf("Loop data: %d\n", ptr2->data);
	 ptr2->next = NULL;
}


void detect_loop(struct node* head)
{
	 struct node* fast_ptr = head;
	 struct node* slow_ptr = head;

	 while((fast_ptr != NULL) && (fast_ptr->next != NULL))
	 {
		  fast_ptr = fast_ptr->next->next;
		  slow_ptr = slow_ptr->next;

		  if(fast_ptr == slow_ptr)
		  {
				printf("\nLoop Found\n");
				printf("\n Slow pointer = %d\n", slow_ptr->data);
				remove_loop(slow_ptr, head);
				return;
		  }
	 }
	 printf("\nLoop not found");
	 printf("\nMiddle Element is: %d", slow_ptr->data);
}

int main()
{
	 struct node* head = NULL;
	 struct node* tmp = NULL;
	 int data = 0;

	 printf("\n");
	 push (&head, 1);
	 push (&head, 2);
	 push (&head, 3);
	 push (&head, 4);
	 push (&head, 5);
	 push (&head, 6);

	 display (head);

	 printf("\n");
	 middle_element(head);

	 /*create loop*/
	 printf("\n%d\n",head->next->next->next->next->next->data); 
	 head->next->next->next->next->next = head->next->next->next;

	 detect_loop(head);

	 printf("\n");
	 display_recursion(head);

	 printf("\n\nReverse");
	 reverse(&head);
	 /*display data using recursive function*/
	 display_recursion (head);


	 printf("\n");
	 while(head != NULL)
	 {
		  data = pop (&head);
		  printf ("\nPop: %d", data);
	 }

	 return 0;
}
