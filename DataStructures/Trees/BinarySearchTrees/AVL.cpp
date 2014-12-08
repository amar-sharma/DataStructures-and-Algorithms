#include <iostream>
#include <stdlib.h>
using namespace std;

struct AVLNode
{
    int data;
    int height;
    AVLNode *left;
    AVLNode *right;
    AVLNode(int d)
    {
        data = d;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

void preorder(AVLNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " (" << root->height << ") ";
    preorder(root->left);
    preorder(root->right);
}

AVLNode *createAVL()
{
    AVLNode *root = NULL;
    return root;
}

int height(AVLNode *root)
{
    return root ? root->height : -1;
}

int heightDifference(AVLNode *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

void fixHeight(AVLNode *root)
{
    if (!root)
        return;
    int h1 = height(root->left), h2 = height(root->right);
    root->height = (h1 > h2 ? h1 : h2 ) + 1;
}

void RRotate(AVLNode *&root)
{
    cout << "RRotate on: " << root->data << endl;
    AVLNode *x = root->left;
    root->left = x->right;
    x->right = root;
    root = x;
    fixHeight(root->right);
    fixHeight(root);
}

void LRotate(AVLNode *&root)
{
    cout << "LRotate on: " << root->data << endl;
    AVLNode *x = root->right;
    root->right = x->left;
    x->left = root;
    root = x;
    fixHeight(root->left);
    fixHeight(root);
}

void balance(AVLNode *&root)
{
    fixHeight(root);
    if (heightDifference(root) == 2)
    {
        if (heightDifference(root->left) < 0)
            LRotate(root->left);
        RRotate(root);
    }
    else if (heightDifference(root) == -2)
    {
        if (heightDifference(root->right) > 0)
            RRotate(root->right);
        LRotate(root);
    }
}

void insertAVL(AVLNode *&root, int d)
{
    if (root == NULL)
    {
        root = new AVLNode(d);
        balance(root);
    }
    else
    {
        if (root->data < d)
        {
            insertAVL(root->right, d);
            balance(root);
        }
        else
        {
            insertAVL(root->left, d);
            balance(root);
        }
    }
}

int main()
{
    AVLNode *root = NULL;
    int N, i, j;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> j;
        insertAVL(root, j);
        preorder(root);
        cout << endl;
    }
    return 0;
}
