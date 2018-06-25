#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
        char data;
        struct node* next;
}Node;

void createList(Node**, int);
void push(Node**, char);
char pop(Node**);
void printList(Node*);
