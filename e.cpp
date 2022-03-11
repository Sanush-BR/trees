// iterative inorder
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

void printInorder(vector<int> &inorder, node *root)
{
    stack<node *> st;
    node *temp = root;

    while (true)
    {
        if (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            temp = st.top();
            st.pop();
            inorder.push_back(temp->data);
            temp = temp->right;
        }
    }
}

void printPostOrder(vector<int> &postorder, node *root)
{
    // Postorder traversal using 2 stacks
    stack<node *> st1, st2;
    if (root == NULL)
        return;
    st1.push(root);

    while (!st1.empty())
    {
        node *temp = st1.top();
        st1.pop();
        st2.push(temp);

        if (temp->left != NULL)
            st1.push(temp->left);
        if (temp->right != NULL)
            st1.push(temp->right);
    }

    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
}

void printPostOrder2(vector<int> &postorder, node *root)
{
    node *curr = root;
    node *temp;
    stack<node *> st;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
}

int main()
{
    vector<int> inorder;
    vector<int> postorder;

    node *root = new node(5);
    root->left = new node(8);
    root->right = new node(10);
    root->left->left = new node(12);
    root->left->right = new node(14);
    root->right->left = new node(16);
    root->right->right = new node(18);

    // printInorder(inorder, root);
    // cout << "Inorder traversal is:" << endl;
    // for (int value : inorder)
    // {
    //     cout << value << " ";
    // }
    // printPostOrder(postorder, root);
    cout << "Postorder traversal is:" << endl;
    printPostOrder2(postorder, root);
    for (int value : postorder)
    {
        cout << value << " ";
    }

    return 0;
}