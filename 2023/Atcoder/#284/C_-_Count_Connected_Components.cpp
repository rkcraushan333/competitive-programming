#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
vector<int> adj[101];
vector<bool> vis(101, 0);
void create(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(int s)
{
    if (vis[s])
        return;
    vis[s] = 1;
    for (auto &i : adj[s])
    {
        dfs(i);
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        create(u, v);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            res++;
        }
    }
    cout << res << endl;
    return 0;
}