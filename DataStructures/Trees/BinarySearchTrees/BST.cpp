#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct BSTreeNode{

	int data;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
}BSTNode;

BSTNode* createBST()
{
	BSTNode *root = NULL;
	return root;
}

void insertBST(BSTNode  * &root,int d){
	if(root==NULL){
		root = (BSTNode *)malloc(sizeof(BSTNode));
		root->data = d;
		root->left = NULL;
		root->right = NULL;
	}
	else{
		if(root->data < d){
			insertBST(root->right,d);
		}
		else{
			insertBST(root->left,d);
		}
	}
}

void inorder(BSTNode *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	BSTNode *root= NULL;
	int N,i,j;
	cin>>N;
	for(i=0;i<N;i++){
		cin >> j;
		insertBST(root,j);
	}
	inorder(root);
	return 0;
}
