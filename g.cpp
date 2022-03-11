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

int count(node *root)
{
    if (root != NULL)
    {
        return count(root->left) + count(root->right) + 1;
    }
    return 0;
}

int SumOfNode(node *root)
{
    if (root != NULL)
    {
        return SumOfNode(root->left) + SumOfNode(root->right) + root->data;
    }
    return 0;
}

int height(node *root)
{
    int lh, rh;
    if (root != NULL)
    {
        lh = height(root->left);
        rh = height(root->right);

        return 1 + max(lh, rh);
    }
    return 0;
}

int main()
{
    int res;
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->left->left = new node(6);
    root->right->left->right = new node(7);

    // res = count(root);
    // cout << "No of nodes in Binary Tree:" << res << endl;
    // res = SumOfNode(root);
    // cout << endl
    //      << "Sum of All the Nodes in Binary Tree:" << res << endl;
    res = height(root);
    cout << endl
         << "Height of binary tree:"
         << res << endl;

    return 0;
}