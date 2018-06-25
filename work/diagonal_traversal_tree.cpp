#include<iostream>
#include<map>
#include<vector>
#include<iterator>
//#include<bits/stdc++.h>

extern "C"{
#include"bst.h"
}

using namespace std;

void diagonalPrintUtil(Node* root, int d, map<int, vector<int> > &mp)
{
	if(!root)
		return;

	mp[d].push_back(root->data);

	diagonalPrintUtil(root->left, d+1, mp);

	diagonalPrintUtil(root->right, d, mp);
}

void diagonalPrint(Node* root)
{
	map<int,vector<int> > mp;
	map<int,vector<int> > :: iterator it;
	vector<int>  :: iterator itr;

	diagonalPrintUtil(root, 0, mp);

	for(it = mp.begin(); it != mp.end(); it++)
	{
		for(itr = it->second.begin(); itr != it->second.end(); itr++)
		{
			cout<<*itr<<" ";
		}
		cout<<endl;	
	}
}

int main()
{
	Node* root = NULL;
	
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 70);
	insert(root, 90);

	diagonalPrint(root);

	
	return 0;
}
