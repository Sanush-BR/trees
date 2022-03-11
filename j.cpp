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

int maxLen(node *root, int &diameter) // diameter
{
    if (root == NULL)
        return 0;

    int lh = maxLen(root->left, diameter);
    int rh = maxLen(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

int main()
{
    int ma = 0;
    int res;
    struct node *root = new node(3);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(17);

    maxLen(root, ma);
    cout << ma << endl;

    return 0;
}