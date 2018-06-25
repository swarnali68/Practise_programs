#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>

using namespace std;

typedef struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}BinaryTreeNode;

BinaryTreeNode* createNode(int data)
{
	BinaryTreeNode* node = (BinaryTreeNode*) malloc (sizeof(BinaryTreeNode));

	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void insertBinaryTree(BinaryTreeNode* root, int data)
{
	BinaryTreeNode* temp = NULL;

	if(!root)
	{
		root = createNode(data);
		return;	
	}
	
	queue<BinaryTreeNode*> q;
	q.push(root);

	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp->left)
		{
			q.push(temp->left);
		}
		else
		{
			temp->left = createNode(data);
			return;
		}
		if(temp->right)
		{
			q.push(temp->right);
		}
		else
		{
			temp->right = createNode(data);
			return;
		}
	}
}
void preorder(BinaryTreeNode* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(BinaryTreeNode* root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void postorder(BinaryTreeNode* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

void levelorder(BinaryTreeNode* root)
{
	BinaryTreeNode* temp;

	if(!root)
	{
		return;
	}
	queue<BinaryTreeNode*> q;
	stack<BinaryTreeNode*> s;
	q.push(root);

	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		//cout<<temp->data<<" ";

		if(temp->left)
			q.push(temp->left);

		if(temp->right)
			q.push(temp->right);

		s.push(temp);
	}
	while(!s.empty())
	{
		temp = s.top();
		s.pop();
		cout<<temp->data<<" ";
	}
}
int main()
{
	BinaryTreeNode* root = NULL;

	root = createNode(1);

	insertBinaryTree(root, 2);
	insertBinaryTree(root, 3);
	insertBinaryTree(root, 4);
	insertBinaryTree(root, 5);
	insertBinaryTree(root, 6);
	insertBinaryTree(root, 7);

	cout<<"\nPreorder: ";
	preorder(root);
	cout<<"\nInorder: ";
	inorder(root);
	cout<<"\nPostorder: ";
	postorder(root);
	cout<<"\nLevelorder: ";
	levelorder(root);
	cout<<endl;

	return 0;
}
