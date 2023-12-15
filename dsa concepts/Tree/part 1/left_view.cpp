// print left Iterrative approach

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int data)
    {
        key = data;
        left = NULL;
        right = NULL;
    }
};

void print_left(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    cout << root->key << " ";
    while (q.size() > 1)
    {
        node *t = q.front();
        q.pop();
        if (t == NULL)
        {
            node *k = q.front();
            cout << k->key << " ";
            q.push(NULL);
            continue;
        }
        if (t->left != NULL)
            q.push(t->left);
        if (t->right != NULL)
            q.push(t->right);
    }
}

int main()
{
    node *root = new node(10);
    root->left = new node(50);
    root->right = new node(60);
    root->right->left = new node(70);
    root->right->left->right = new node(8);
    root->right->right = new node(20);
    print_left(root);
    return 0;
}