// tree creation and DFS(Preorder,Inorder,Postorder)

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    struct node *root;
    root = new node(5);
    root->left = new node(10);
    root->right = new node(20);
    root->left->left = new node(30);
    root->left->right = new node(40);
    root->right->left = new node(50);
    root->right->right = new node(60);

    cout << "PREORDER:" << endl;
    preorder(root);
    cout << endl
         << "INORDER" << endl;
    inorder(root);
    cout << endl
         << "POSTORDER" << endl;
    postorder(root);

    return 0;
}