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
void print_k_nodes(node *root, int n, int i = 0)
{
    if (root == NULL)
        return;
    if (i == n)
    {
        cout << root->key << " ";
        return;
    }
    print_k_nodes(root->left, n, i + 1);
    print_k_nodes(root->right, n, i + 1);
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
    int k = 0;
    cin >> k;
    print_k_nodes(root, k);
    return 0;
}