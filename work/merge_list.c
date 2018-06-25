#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	 int data;
	 struct node* next;
}Node;

Node* createSortedList(int size)
{
	 Node* head = NULL, * ptr = NULL, *temp = NULL;
	 //int val = rand() % 500;
	 //int val[4] = {2,5,10,12};
	 int val[4] = {1, 4, 5, 9};
	 int itr = 0;

	 while(itr < size){

		  temp = (Node*)malloc(sizeof(Node));
		  temp->data = val[itr];
		  //val += rand() % 500;
		  temp->next = NULL;

		  if(head == NULL){
				head = ptr = temp;
		  }
		  else{
				ptr->next = temp;
				ptr = ptr->next;
		  }

		  itr++;
	 }

	 return head;
}

Node* createSortedList2(int size)
{
	 Node* head = NULL, * ptr = NULL, *temp = NULL;
	 //int val = rand() % 500;
	 //int val[2] = {1,3};
	 int val[3] = {2, 6, 8};
	 int itr = 0;

	 while(itr < size){

		  temp = (Node*)malloc(sizeof(Node));
		  temp->data = val[itr];
		  //val += rand() % 500;
		  temp->next = NULL;

		  if(head == NULL){
				head = ptr = temp;
		  }
		  else{
				ptr->next = temp;
				ptr = ptr->next;
		  }

		  itr++;
	 }

	 return head;
}
Node* merge_list(Node*head1, Node* head2)
{
	 Node* head = NULL;
	 Node* ptr = NULL;

	 if(head1->data > head2->data)
	 {
		  ptr = head2;
		  head2 = head2->next;
		  ptr->next = head1;
		  head1 = ptr;
	 }
	 head = head1;
	 ptr = NULL;

	 while (head1->next != NULL)
	 {
		  if(head1->next->data > head2->data)
		  {
				ptr = head1->next;
				head1->next = head2;
				if(head2->next != NULL)
					head2 = head2->next;
				else
					head2 = NULL;
				head1->next->next = ptr;

		  }
		  head1 = head1->next;
		  if(!head2)
		  {
				break;
		  }
	 }
	 if(head2 != NULL)
	 {
		  head1->next = head2;
	 }
	 
	return (head);
}


void printList(Node* head)
{
    while(head != NULL){
	  printf("%d ",head->data);
	  head = head->next;
    }
    printf("\n");
}

int main()
{
	 Node* head1 = NULL;
	 Node* head2 = NULL;
	 Node* result = NULL;

	 head1 = createSortedList(4);
	 head2 = createSortedList2(3);
         
         printList(head1);
         printList(head2);

	 result = merge_list(head1, head2);
         printList(result);

	 return 0;
}


