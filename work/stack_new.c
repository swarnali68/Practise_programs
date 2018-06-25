
#include<stdio.h>

#include "stack_new.h"

void push(Stack *s, int data)
{
	Node* temp = (Node*) malloc (sizeof(Node));

	temp->data = data;
	temp->next = NULL;

	if (s->top == NULL)
	{
		s->top = temp;
	}
	else
	{
		temp->next = s->top;
		s->top = temp;
	}	
}

int pop(Stack *s)
{
	Node* temp = NULL;
	int data = -1;

	if (s->top != NULL)
	{
		temp = s->top;
		data = s->top->data;
		s->top = s->top->next;
		free (temp);
	}

	return data;
}

/*int main()
{
	Stack s;
	int data;

	s.top = NULL;

	push(&s, 10);

	data = pop(&s);
	printf("%d\n", data);

	return 0;
}*/
