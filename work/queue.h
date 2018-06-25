#include<stdio.h>

#ifndef NODE_
#define NODE_

typedef struct node
{
        int data;
        struct node* next;
}Node;

#endif

typedef struct queue 
{
        Node* front;
        Node* rear;
	int size;
}Queue;

int dequeue(Queue*);
void enqueue(Queue* , int);


