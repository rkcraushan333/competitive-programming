// children sum property
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
bool childrenSumProperty(node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    int a = root->key;
    int b = root->left->key;

    if (root->left == NULL)
    {
        b = 0;
    }
    int c = root->right->key;

    if (root->right == NULL)
    {
        c = 0;
    }
    return (a == b + c) && childrenSumProperty(root->left) && childrenSumProperty(root->right);
}
int main()
{
    node *root = new node(3);
    root->left = new node(1);
    root->right = new node(2);
    root->right->left = new node(1);
    root->right->right = new node(2);
    if (childrenSumProperty(root))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}