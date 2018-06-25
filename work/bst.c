#include"bst.h"

Node* newNode(int data)
{
	Node* node = NULL;

	node = (Node*) malloc (1 * sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

Node* insert(Node* node, int key)
{
	if (node == NULL)
		return (newNode(key));	

	if(key < node->data)
		node->left = insert(node->left, key);
	else
		node->right= insert(node->right, key);

	return node;
}
Node* find_min(Node* root)
{
	Node* node = root;
	while(node->left != NULL)
	{
		node = node->left;
	}
	return node;
}
Node* delete_node(Node* root, int key)
{
	if (root == NULL)
		return root;

	if(key < root->data)
		root->left = delete_node(root->left, key);
	else if(key > root->data)
		root->right = delete_node(root->right, key);
	else
	{
		if(root->left == NULL)
		{
			Node* temp;
			temp = root->right;
			free (root);
			return temp;	
		}
		else if(root->right == NULL)
		{
			Node* temp;
			temp = root->left;
			free(root);
			return temp;
		}
		
		Node*  min_node;

		min_node = find_min(root->right);

		root->data = min_node->data;

		root->right = delete_node(root->right, min_node->data); 
	}
	return root;
}

void inorder(Node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d \t", root->data);
		inorder(root->right);	
	}
}

/*int main()
{
	Node* root = NULL;

	root = insert(root, 20);
	insert(root, 50);
	insert(root, 30);
	insert(root, 80);
	insert(root, 40);
	insert(root, 10);

	root = insert(root, 100);
	insert(root, 900);
	insert(root, 650);
	insert(root, 500);
	insert(root, 700);
	insert(root, 670);
	insert(root, 800);
	insert(root, 1000);*/

	/*int i = 0;
	int n = 0;
	int data = 0;

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("Enter the number: ");
		scanf("%d", &data);
		if (i == 0)
			root = insert(root, data);
		else
			insert(root, data); 
	}

	inorder(root);
	
	printf("\n");

	printf("Enter the number to delete: ");
	scanf("%d", &data);

	root = delete_node(root, data);

	inorder(root);	

	printf("\n");	

	return 0;
}*/
