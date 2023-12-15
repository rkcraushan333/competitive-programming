// Time complexity  O(n^2)
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
bool checkBalanced(node *root)
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh - rh) <= 1 && checkBalanced(root->left) && checkBalanced(root->right));
}
int main()
{
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    if (checkBalanced(root))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}