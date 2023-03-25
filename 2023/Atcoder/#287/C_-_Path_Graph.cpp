#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
bool iscycle(vector<int> adj[], int s, vector<bool> &vis, int par)
{
    vis[s] = 1;
    for (auto k : adj[s])
    {
        if (vis[k] && k != par)
            return true;
        if (!vis[k])
            if (iscycle(adj, k, vis, s))
                return true;
    }
    return false;
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<bool> vis(n + 1);
    for (int i = 0; i < m; i++)
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
            if (iscycle(adj, i, vis, -1))
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    vector<int> ind(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (auto j : adj[i])
            ind[j]++;
    }
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 1)
            a++;
        else if (ind[i] == 2)
            b++;
    }
    if ((b == n - 2) && (a == 2))
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}