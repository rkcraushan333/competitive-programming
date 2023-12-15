// print line by line M-2

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

int maxm(node *root)
{
    if (root == NULL)
        return INT_MIN;

    return max(root->key, max(maxm(root->left), maxm(root->right)));
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->right = new node(6);
    root->left->left = new node(8);
    root->left->right = new node(7);
    root->left->right->left = new node(9);
    root->left->right->right = new node(15);
    cout << maxm(root);
    return 0;
}