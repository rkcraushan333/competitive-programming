#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int data)
    {
        key = key;
        left = NULL;
        right = NULL;
    }
};

node *lca(node *root, int n1, int n2)
{
    if (root == NULL || root->key == n1 || root->key == n2)
        return root;
    node *l = lca(root->left, n1, n2);
    node *r = lca(root->right, n1, n2);
    if (l == NULL)
        return r;
    else if (r == NULL)
        return l;
    else
        return root;
}
int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->right = new node(60);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->left->right->left = new node(70);
    root->left->right->right = new node(80);
    cout << lca(root, 40, 80)->key;
    return 0;
}
