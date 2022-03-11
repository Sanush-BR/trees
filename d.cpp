// iterative Preorder without reccursion
// Time and Space both O(N)
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

void printPreorder(vector<int> &preorder, node *root)
{
    stack<node *> st;
    node *temp;

    if (root == NULL)
        return;

    st.push(root);

    while (!st.empty())
    {
        temp = st.top();
        st.pop();
        preorder.push_back(temp->data);

        if (temp->right != NULL)
            st.push(temp->right);

        if (temp->left != NULL)
            st.push(temp->left);
    }
}

int main()
{
    vector<int> preorder;

    node *root = new node(5);
    root->left = new node(8);
    root->right = new node(10);
    root->left->left = new node(12);
    root->left->right = new node(14);
    root->right->left = new node(16);
    root->right->right = new node(18);

    printPreorder(preorder, root);
    cout << "Preorder traversal is:" << endl;
    for (int value : preorder)
    {
        cout << value << " ";
    }

    return 0;
}