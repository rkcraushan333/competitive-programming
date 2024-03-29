#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc

// based on bipartite graph
int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> ans;
bool dfs(int s, int i = 1)
{
    vis[s] = 1;
    ans[s] = i;
    for (auto &x : adj[s])
    {
        if (!vis[x])
        {
            if (!dfs(x, !i))
                return false;
        }
        else
        {
            if (ans[x] == i)
                return false;
        }
    }
    return true;
}
signed main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    ans.resize(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (!dfs(i))
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (ans[i] == 0 ? 2 : 1) << " ";
    }
    return 0;
}