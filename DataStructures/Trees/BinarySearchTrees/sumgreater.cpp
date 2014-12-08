#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct BSTreeNode
{

	int data;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
} BSTNode;

BSTNode* createBST()
{
	BSTNode *root = NULL;
	return root;
}

void sumGreater(BSTNode *root, int *sum)
{
	    if (root->right == NULL)
	    {
	        *sum+=root->data;
	        root->data = *sum;
	        return;
	    }
	     
			sumGreater(root->right,sum);
			*sum += root->data;
	    root->data = *sum;
			sumGreater(root->left,sum);
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
//	inorder(root);
	i = 0 ;
	sumGreater(root, &i);
	inorder(root);
	return 0;
}
