#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

typedef struct BinarySearchTreeNode
{
	int data;
	BinarySearchTreeNode* left;
	BinarySearchTreeNode* right;
}BSTNode;

BSTNode* createnode(int data)
{
	BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));

	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BSTNode* insert(BSTNode* root, int data)
{
	if(root == NULL)
	{
		root = createnode(data);
	}	
	else
	{
		if(data < root->data)
			root->left = insert(root->left, data);
		else if(data > root->data)
			root->right = insert(root->right, data);
	}
	
	return root;
}

BSTNode* findmin(BSTNode* node)
{
	BSTNode* min_node = node;

	while(min_node->left != NULL)
	{
		min_node = min_node->left;
	}
	return min_node;
}

BSTNode* deleteNode(BSTNode* root, int data)
{
	if(root == NULL)
		return root;
	else if(data < root->data)
		root->left = deleteNode(root->left,data);
	else if(data > root->data)
		root->right = deleteNode(root->right,data);
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
			return root;
		}

		else if(root->left == NULL)
		{
			BSTNode* temp = root;
			root = root->right;
			free(temp);
			temp = NULL;
			return root;
		}
		else if(root->right == NULL)
		{
			BSTNode* temp = root;
			root = root->left;
			free(temp);
			temp = NULL;
			return root;
		}
		else
		{
			BSTNode* min_node = NULL;
			min_node = findmin(root->right);
			root->data = min_node->data;
			root->right = deleteNode(root->right,min_node->data);
		}
	}
	return root;
}

void levelordertraversal(BSTNode* root)
{
	if(!root)
		return;

	queue<BSTNode*> q;
	q.push(root);

	while(!q.empty())
	{
		BSTNode* temp = q.front();
		q.pop();

		cout<<temp->data<<"\t";

		if(temp->left)
			q.push(temp->left);

		if(temp->right)
			q.push(temp->right);
	}
	cout<<endl;
}
int main()
{
	BSTNode* root = NULL;
	root = insert(root,6);
	insert(root,2);
	insert(root,8);
	insert(root,1);
	insert(root,4);
	insert(root,3);
	insert(root,5);

	levelordertraversal(root);

	deleteNode(root,2);

	levelordertraversal(root);

	return 0;	
}
