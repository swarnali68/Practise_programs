#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
        int data;
        struct node* left;
        struct node* right;
}Node;

Node* newNode(int );

Node* insert(Node* , int );

Node* find_min(Node* );

Node* delete_node(Node* , int );

