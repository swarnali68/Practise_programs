#include <stdio.h>
#include <stdlib.h>

typedef struct bfsnode
{
	int data;
	struct bfsnode* left;
	struct bfsnode* right;
}bfsNode;


typedef struct queuenode
{
	bfsNode* node;
	struct queuenode* next;
}queueNode;

bfsNode* newnode (int data)
{
	bfsNode* temp;

	temp = (bfsNode *) malloc (sizeof(bfsNode));
	
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void enqueu(queueNode** front, queueNode** rear, bfsNode* bfsnode)
{
	queueNode* temp = (queueNode*) malloc (1 * sizeof(queueNode));

	temp->node = bfsnode;
	temp->next = NULL;

	if(*front == NULL)
	{
		*front = temp;
		*rear = temp;
	}
	else
	{
		(*rear)->next = temp;
		*rear = (*rear)->next;		
	}
}

bfsNode* dequeu(queueNode** front, queueNode** rear)
{
	bfsNode* node;
	queueNode* temp;

	if(*front == NULL)
		return NULL;

	else if(*front == *rear)
	{
		temp = (*front);
		node = (*front)->node;	
		*front = *rear = NULL;
		free(temp);
		return node;
	}
	else if (*front)
	{
		temp = (*front);
		node = (*front)->node;
		*front = (*front)->next;
		free(temp);
		return node;
	}	
}
void bfs (bfsNode* root)
{
	bfsNode* tempnode = NULL;
	queueNode* front = NULL;
	queueNode* rear = NULL;

        tempnode = root;

	while(tempnode)	
	{

		printf("%d", tempnode->data);
		if(tempnode->left)
			enqueu(&front, &rear, tempnode->left);
		if(tempnode->right)
			enqueu(&front, &rear, tempnode->right);

		tempnode = dequeu(&front, &rear);
	}
}

int main()
{
	bfsNode* root = NULL;

	root = newnode (1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);

	bfs(root);

	return 0;
}
