#include <bits/stdc++.h>
using namespace std;

// by inforkc
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> inorder(v + 1);
    vector<int> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inorder[b]++;
    }
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= v; i++)
    {
        if (inorder[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int c = q.top();
        res.push_back(c);
        q.pop();
        for (auto i : adj[c])
        {
            inorder[i]--;
            if (inorder[i] == 0)
                q.push(i);
        }
    }
    if (res.size() < v)
    {
        cout << "Sandro fails." << endl;
    }
    else
    {
        for (auto i : res)
        {
            cout << i << " ";
        }
    }
    return 0;
}