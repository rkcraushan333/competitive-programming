// print left recursive approach (using preorder traversal)

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
int maxlevel = 0;
void print_left(node *root, int level)
{
    if (root == NULL)
        return;
    if (maxlevel < level)
    {
        cout << root->key << " ";
        maxlevel = level;
    }
    print_left(root->left, level + 1);
    print_left(root->right, level + 1);
}

int main()
{
    node *root = new node(10);
    root->left = new node(50);
    root->right = new node(60);
    root->right->left = new node(70);
    root->right->left->right = new node(8);
    root->right->right = new node(20);

    print_left(root, 1);
    return 0;
}