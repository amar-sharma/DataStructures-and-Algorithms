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

int SearchIn(int a[],int s,int e,int d)
{
	int i;
	for (int i = s; i < e; ++i)
	{
		if(a[i]==d)
			return i;
	}
}

BSTNode* createBSTpreIn(int pre[],int in[],int inStr,int inEnd)
{
	static int preIndex = 0;
	BSTNode *temp = NULL;
	if(inStr > inEnd)
		return NULL;
	temp = (BSTNode *)malloc(sizeof(BSTNode));
	if(!temp){
		cout<< "WTF!!!!"; 
	}
	temp->data = pre[preIndex];
	preIndex++;
	if(inStr==inEnd) return temp;
	int inIND = SearchIn(in,inStr,inEnd,temp->data);
	temp->left = createBSTpreIn(pre,in,inStr,inIND-1);
	temp->right = createBSTpreIn(pre,in,inIND+1,inEnd);
	return temp;
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
	int in[] = {1,2,3,4,5,6};
	int pre[] = {4,2,1,3,5,6};
	root = createBSTpreIn(pre,in,0,5);
	inorder(root);
	return 0;
}
