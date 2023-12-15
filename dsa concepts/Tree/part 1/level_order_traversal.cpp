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
int height(node *root)
{
    if (root == NULL)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}
void print_level(node *root, int n)
{
    if (root == NULL)
        return;
    if (n == 0)
    {
        cout << root->key << " ";
        return;
    }
    print_level(root->left, n - 1);
    print_level(root->right, n - 1);
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
    int k = height(root);
    for (int i = 0; i < k; i++)
    {
        print_level(root, i);
    }
    return 0;
}