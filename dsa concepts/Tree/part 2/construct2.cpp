// using inorder and preorder
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int data)
    {
        key = data;
        left = NULL;
        right = NULL;
    }
};

node *construct(int in[], int post[], int is, int ie)
{
    static int postindex = ie;
    if (is > ie)
        return NULL;
    node *root = new node(post[postindex--]);
    int index;
    for (int i = is; i <= ie; i++)
    {
        if (in[i] == root->key)
        {
            index = i;
            break;
        }
    }
    root->right = construct(in, post, index + 1, ie);
    root->left = construct(in, post, is, index - 1);
    return root;
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
int main()
{
    int in[8] = {40, 20, 50, 10, 30, 80, 70, 90};
    int post[8] = {40, 50, 20, 80, 90, 70, 30, 10};
    node *root = construct(in, post, 0, 7);
    inorder(root);
    return 0;
}