#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct BSTNode
{

	int data;
	struct BSTNode *left;
	struct BSTNode *right;
} BSTNode;

BSTNode* createBST()
{
	BSTNode *root = NULL;
	return root;
}

void insertBST(BSTNode  * &root, int d)
{
	if (root == NULL)
	{
		root = (BSTNode *)malloc(sizeof(BSTNode));
		root->data = d;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (root->data < d)
		{
			insertBST(root->right, d);
		}
		else
		{
			insertBST(root->left, d);
		}
	}
}

BSTNode * FindMax(BSTNode *root)
{
	while (root)
	{
		if (root->right == NULL) break;
		root = root->right;
	}
	return root;
}

BSTNode *deleteBST(BSTNode *root,int x)
{
		BSTNode *temp;
		if(root==NULL)
				cout << "NOT FOUND!!";
		else if(root->data > x) 
				root->left = deleteBST(root->left,x);
		else if(root->data < x)
				root->right = deleteBST(root->right,x);
		else{
				if(root->left && root->right)
				{
					temp = FindMax(root->left);
					root->data = temp->data;
					root->left = deleteBST(root->left,root->data);
				}
				else
				{
						temp = root;
						if(root->left == NULL)
								root=root->right;
						else if(root->right == NULL)
								root = root->left;
						free(temp);
				}
		}
		return root;
}



void deleteBSTI(BSTNode *&root, int x)
{
	BSTNode *temp = root;
	BSTNode *prev;
	while (temp)
	{
		if (temp->data == x)
		{
			BSTNode *t;
			if (temp->left && temp->right)
			{
				t = FindMax(temp->left);
				x = temp->data = t->data;
			}
			else
			{
				t = temp;
				if(!temp->right)
						prev->right = temp->left;
				else if(!temp->left)
						prev->right = temp->right;
				else
						prev->right = NULL;
				free(t);
				break;
			}
		}
		prev = temp;
		if (temp->data < x)
			temp = temp->right;
		else
			temp = temp->left;
	}
}

void inorder(BSTNode *root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	inorder(root->left);
	inorder(root->right);
}

int main()
{
	BSTNode *root = NULL;
	int N, i, j;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> j;
		insertBST(root, j);
	}
	inorder(root);
	cout << endl;
	root = deleteBST(root, 1);
	inorder(root);
	cout << endl;
	deleteBST(root, 5);
	inorder(root);
	cout << endl;
	return 0;
}
