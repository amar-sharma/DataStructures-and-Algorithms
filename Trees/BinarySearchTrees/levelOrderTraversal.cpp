#include<iostream>
#include<stdlib.h>
#include<queue>

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

void levelOrderBST(BSTNode *root){
	queue<BSTNode*> q;
	BSTNode *temp;
	if(!root){
		return;
	}
	q.push(root);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
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
	levelOrderBST(root);
	return 0;
}
