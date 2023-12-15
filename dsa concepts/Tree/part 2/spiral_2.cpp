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
    queue<node *> q;
    queue<int> q1;
    stack<int> s;
    q.push(root);
    while (!q.empty())
    {
        int k = q.size();
        for (int i = 0; i < k; i++)
        {
            node *t = q.front();
            q.pop();
            if (c & 1)
                s.push(t->key);
            else
                q1.push(t->key);
            if (t->left != NULL)
                q.push(t->left);
            if (t->right != NULL)
                q.push(t->right);
        }
        if (c & 1)
        {
            while (!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
        }
        else
        {
            while (!q1.empty())
            {
                cout << q1.front() << " ";
                q1.pop();
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