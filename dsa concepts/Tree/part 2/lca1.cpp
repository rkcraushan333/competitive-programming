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
bool findPath(node *root, vector<node *> &p, int n)
{
    if (root == NULL)
        return false;
    p.push_back(root);
    if (root->key == n)
        return true;
    if (findPath(root->left, p, n) || findPath(root->right, p, n))
        return true;
    p.pop_back();
    return false;
}

node *lca(node *root, int n1, int n2)
{
    vector<node *> v1, v2;
    if ((!findPath(root, v1, n1)) || (!findPath(root, v2, n2)))
        return NULL;
    int i;
    for (i = 1; (i < v1.size()) && (i < v2.size()); i++)
    {
        if (v1[i] != v2[i])
            break;
    }
    return v1[i - 1];
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
    node *t = lca(root, 40, 80);
    if (t != NULL)
        cout << t->key;
    return 0;
}
