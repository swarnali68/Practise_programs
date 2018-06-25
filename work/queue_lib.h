#include <stdio.h>

typedef struct node
{
	int data;
	struct node* next;
}Node;

void enqueu(Node**, Node**, int);
int dequeu(Node**, Node**);
void printqueu(Node*);
