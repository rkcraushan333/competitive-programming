// Efficient solution
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
void printSpiral(node *root)
{
    int c = 0;
    stack<node *> s1;
    stack<node *> s2;
    s1.push(root);
    while ((!s1.empty()) || (!s2.empty()))
    {
        int k = max(s1.size(), s2.size());
        for (int i = 0; i < k; i++)
        {
            if (c & 1)
            {
                node *t = s2.top();
                s2.pop();
                cout << t->key << " ";
                if (t->right != NULL)
                    s1.push(t->right);
                if (t->left != NULL)
                    s1.push(t->left);
            }
            else
            {
                node *t = s1.top();
                s1.pop();
                cout << t->key << " ";
                if (t->left != NULL)
                    s2.push(t->left);
                if (t->right != NULL)
                    s2.push(t->right);
            }
        }
        c++;
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->left->left = new node(10);
    root->right->right = new node(7);
    printSpiral(root);
    return 0;
}