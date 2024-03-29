#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
vector<vector<int>> adj;
vector<bool> vis;
void dfs(int s)
{
    vis[s] = true;
    for (auto &i : adj[s])
    {
        if (!vis[i])
            dfs(i);
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool k = 0, a;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            if (!k)
            {
                k = 1;
                a = i;
            }
            else
            {
                v.push_back({a, i});
                a = i;
            }
        }
    }
    cout << v.size() << endl;
    for (auto &i : v)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}