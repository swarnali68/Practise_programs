#include<stdio.h>
#include<stdlib.h>

#ifndef NODE_
#define NODE_
typedef struct node
{
	int data;
	struct node* next;
}Node;
#endif

typedef struct stack
{
	Node* top;
}Stack;

void push (Stack*, int data);
int pop (Stack*);
