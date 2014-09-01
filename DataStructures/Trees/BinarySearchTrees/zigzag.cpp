#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>

using namespace std;

typedef struct BSTreeNode{

	int data;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
}BSTNode;


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

void zigzagBST(BSTNode *root)
{
	stack <BSTNode*> c,n,t;
	BSTNode *temp;
	bool b = false;
	if(!root)
		return;
	c.push(root);
	c.push(NULL);
	while(!c.empty()){
		temp = c.top();
		c.pop();
		if(temp){
			cout << temp->data <<" ";
			if(b){
				if(temp->left) n.push(temp->left);
				if(temp->right) n.push(temp->right);
			}
			else{
				if(temp->right) n.push(temp->right);
				if(temp->left) n.push(temp->left);
			}	
		}
		if(c.empty()){
			b=!b;
			t = c;
			c = n;
			n = t;
		}
	}
}

int main(){
	BSTNode *root= NULL;
	int N,i,j;
	cin>>N;
	for(i=0;i<N;i++){
		cin >> j;
		insertBST(root,j);
	}
	//	inorder(root);
	zigzagBST(root);
	return 0;
}
