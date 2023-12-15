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

node *inorder(node *root)
{
    static node *prev = NULL;

    if (root == NULL)
        return root;
    node *head = inorder(root->left);
    inorder(root->left);
    if (prev == NULL)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    inorder(root->right);
    return head;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->key << " ";
        head = head->right;
    }
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
    node *head = inorder(root);
    print(head);
    return 0;
}