// Checking for the balanced binary tree
// For evey node in balanced binary tree height(left)-height(right)<=1

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

int checkIfBalanced(node *root)
{
    if (root == NULL)
        return 0;

    int lh = checkIfBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = checkIfBalanced(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return max(lh, rh) + 1;
}

int main()
{

    int res;
    struct node *root = new node(3);
    root->left = new node(9);
    root->right = new node(20);
    // root->left->left = new node(4);
    root->right->left = new node(15);
    root->right->right = new node(17);
    // root->right->left->left = new node(5);
    // root->right->left->right = new node(6);

    res = checkIfBalanced(root);
    if (res != -1)
    {
        cout << "Balanced BT" << res;
    }
    else
    {
        cout << "Not balanced BT" << endl;
    }

    return 0;
}
