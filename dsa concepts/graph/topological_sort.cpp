#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    vector<int> inorder(n + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inorder[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (inorder[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        cout << c << " ";
        for (auto i : adj[c])
        {
            inorder[i]--;
            if (inorder[i] == 0)
                q.push(i);
        }
    }
    return 0;
}