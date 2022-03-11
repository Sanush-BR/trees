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

int countLeaf(node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = countLeaf(root->left);
        y = countLeaf(root->right);

        if (root->left == NULL && root->right == NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}
int countNonLeaf(node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = countNonLeaf(root->left);
        y = countNonLeaf(root->right);

        if (root->left != NULL && root->right != NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int main()
{
    int res;
    struct node *root = new node(3);
    root->left = new node(9); // leaf
    root->right = new node(20);
    root->right->left = new node(15);  // leaf
    root->right->right = new node(17); // leaf

    // res = countLeaf(root);
    // cout << "No of leaf nodes are:" << res;
    res = countNonLeaf(root);
    cout << "Non leaf nodes are:" << res;

    return 0;
}