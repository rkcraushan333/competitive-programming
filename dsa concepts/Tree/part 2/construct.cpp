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
node *construct(int in[], int pre[], int is, int ie)
{
    static int preindex = 0;
    if (is > ie)
        return NULL;
    node *root = new node(pre[preindex++]);
    int index;
    for (int i = is; i <= ie; i++)
    {
        if (in[i] == root->key)
        {
            index = i;
            break;
        }
    }
    root->left = construct(in, pre, is, index - 1);
    root->right = construct(in, pre, index + 1, ie);
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
    int pre[8] = {10, 20, 40, 50, 30, 70, 80, 90};
    node *root = construct(in, pre, 0, 7);
    inorder(root);
    return 0;
}