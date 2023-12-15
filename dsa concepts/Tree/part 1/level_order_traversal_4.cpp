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

void print_level(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int i = q.size();
        while (i--)
        {
            node *child = q.front();
            q.pop();
            cout << child->key << " ";
            if (child->left != NULL)
                q.push(child->left);
            if (child->right != NULL)
                q.push(child->right);
        }
        cout << endl;
    }
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
    print_level(root);
    return 0;
}