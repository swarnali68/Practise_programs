#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

typedef struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}BTNode;

BTNode* createNode(int data)
{
	BTNode* node = (BTNode*) malloc(sizeof(BTNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void deleteQueue(queue<BTNode*> &q)
{
	q = queue<BTNode*>();
}

void insertNode(BTNode* root, int data)
{
	if(root == NULL)
	{
		createNode(data);
		return;
	}
	queue<BTNode*> q;
	q.push(root);

	BTNode* temp;

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
			deleteQueue(q);
			return;
		}

		if(temp->right)
		{
			q.push(temp->right);
		}	
		else
		{
			temp->right = createNode(data);
			deleteQueue(q);
			return;
		}
	}
}
void levelordertraversal(BTNode* root)
{
	if(!root)
		return;

	queue<BTNode*> q;
        q.push(root);

        BTNode* temp;

        while(!q.empty())
        {
                temp = q.front();
                q.pop();

		cout<<temp->data<<"\t";

                if(temp->left)
                {
                        q.push(temp->left);
                }

                if(temp->right)
                {
                        q.push(temp->right);
                }
        }
	cout<<endl;
}
BTNode* lca(BTNode* root, int n1, int n2)
{
	BTNode* left;
	BTNode* right;

	if(root == NULL)
		return NULL;

	if((root->data == n1) || (root->data == n2))
		return root;

	left = lca(root->left, n1, n2);
	right = lca(root->right, n1, n2);

	if((left == NULL) && (right == NULL))
		return NULL;

	if((left != NULL) && (right != NULL))
		return root;

	return ((left != NULL)?left:right);
	
}
int main()
{
	BTNode* root = NULL;
	root = createNode(1);
	insertNode(root,2);
	insertNode(root,3);
	insertNode(root,4);
	insertNode(root,5);
	insertNode(root,6);
	insertNode(root,7);

	BTNode* ret = lca(root,4,5);
	if(ret)
		cout<<"LCA = "<<ret->data<<endl;
	else
		cout<<"LCA not found"<<endl;

	levelordertraversal(root);
}
