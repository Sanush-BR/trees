// Level order traversal of binary tree
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;

    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void printLevelOrder(struct node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    node *temp;

    while (!q.empty())
    {
        temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main()
{
    node *root = new node(5);
    root->left = new node(8);
    root->right = new node(10);
    root->left->left = new node(12);
    root->left->right = new node(14);
    root->right->left = new node(16);
    root->right->right = new node(18);

    cout << "Preorder traversal of binary tree:" << endl;
    preorder(root);
    cout << endl
         << "*********************************" << endl;
    cout << "Level order traversal of binary tree is:" << endl;
    printLevelOrder(root);

    return 0;
}