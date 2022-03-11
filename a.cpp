// creating the BT
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create()
{
    struct node *new_node;
    int x;
    new_node = new node();
    cout << "Enter value,enter -1 for no node:" << endl;
    cin >> x;
    if (x == -1)
        return 0;
    new_node->data = x;
    cout << endl
         << "Enter the left child of:" << x << endl;
    new_node->left = create();
    cout << endl
         << "Enter the right child of:" << x << endl;
    new_node->right = create();

    return new_node;
}

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
    root = create();

    cout << endl
         << "preorder:" << endl;
    preorder(root);
    cout << endl
         << "inorder:" << endl;
    inorder(root);
    cout << endl
         << "postorder:" << endl;
    postorder(root);

    return 0;
}