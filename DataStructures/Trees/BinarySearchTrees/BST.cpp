#include <iostream>
#include <stdlib.h>
using namespace std;

class BST
{
protected:
    int height;
    BSTNode *root;
    class BSTNode
    {
    public:
        int data;
        BSTNode *left;
        BSTNode *right;
        BSTNode(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
    };
public:
    BST()
    {
        this->root = NULL;
        this->height = 0;
    }
    void insert(int data)
    {
        insertBST(this->root, data);
    }
    void inorder()
    {
        cout << " Inorder: ";
        inorder(this->root);
        cout << endl;
    }
    ~BST()
    {
        delete this->root;
    }
private:
    void insertBST(BSTNode *&root, int d)
    {
        if (root == NULL)
        {
            root = new BSTNode(d);
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
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main()
{
    BST tree;
    int N, i, j;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> j;
        tree.insert(j);
    }
    tree.inorder();
    return 0;
}
