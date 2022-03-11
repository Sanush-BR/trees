
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

vector<int> pre, in, pos;

void oneTraversal(node *root)
{
    stack<pair<node *, int>> st;
    st.push({root, 1});

    if (root == NULL)
        return;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }

        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }

        else
        {
            pos.push_back(it.first->data);
        }
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    // root->left->right = new node(14);
    root->right->left = new node(6);
    root->right->right = new node(7);

    oneTraversal(root);

    cout << "1.PREORDER IS:" << endl;
    for (int val : pre)
    {
        cout << val << " ";
    }
    cout << endl
         << "2.INORDER IS:" << endl;
    for (int val : in)
    {
        cout << val << " ";
    }
    cout << endl
         << "3.POSTORDER IS:" << endl;
    for (int val : pos)
    {
        cout << val << " ";
    }

    return 0;
}