// Time complexity o(n)
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
int checkBalanced(node *root)
{
    if (root == NULL)
        return 0;
    int lh = checkBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = checkBalanced(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}
int main()
{
    node *root = new node(18);
    // root->left = new node(4);
    root->right = new node(20);
    root->right->left = new node(13);
    root->right->right = new node(70);
    if (checkBalanced(root) == -1)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}