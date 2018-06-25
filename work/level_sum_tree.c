#include"bst.h"

typedef struct qNode
{
	Node* node;
	struct qNode* next;
}QNode;

typedef struct queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

void enqueue(Queue* q, Node* node)
{
	QNode* temp = (QNode *) malloc (sizeof(QNode));

	temp->node = node;
	temp->next = NULL;
		
	if(q->front == NULL)
	{
		q->front  = q->rear = temp;
		q->size++;
	}
	else
	{
		q->rear->next = temp;
		q->rear = temp;
		q->size++;
	}	
}

Node* dequeue(Queue* q)
{
	QNode* temp;
	Node* node = NULL;

	if (q->front != NULL)
	{
		temp = q->front;
		node = q->front->node;
		
		if(q->front == q->rear)
		{
			q->front = q->rear = NULL;
		}
		else
		{
			q->front  = q->front->next;
		}
		q->size--;
		free(temp);	
	}
	return node;
} 


void level_sum_node(Node* root)
{
	int sum = 0;
	int i = 0;
	Node* node  = NULL;
	Queue q;

	q.front  = NULL;
	q.rear = NULL;	

	enqueue(&q, root);

	while(q.size)
	{
		i = q.size;
		sum = 0;
	
		while(i--)
		{
			node = dequeue(&q);
			sum += node->data;
			if(node->left != NULL)
			{
				enqueue(&q,node->left);
			}
			if(node->right != NULL)
			{
				enqueue(&q,node->right);
			}
		}
		printf("Sum = %d\n", sum);
	}
	
}

int main()
{
	Node* root = NULL;

	/*root = insert(root, 1);	
	insert(root, 2);
	insert(root, 3);
	insert(root, 4);*/

	root = insert(root, 20);
        insert(root, 50);
        insert(root, 30);
        insert(root, 80);
        insert(root, 40);
        insert(root, 10);

	
	level_sum_node(root);	

	return 0;
}
