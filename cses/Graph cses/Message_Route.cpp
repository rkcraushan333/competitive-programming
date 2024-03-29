#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int n, m;
vector<vector<int>> adj;
vector<bool> vis;
signed main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> res;
    queue<int> q;
    vector<int> par(n + 1);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (auto &i : adj[k])
        {
            if (!vis[i])
            {
                if (i == n)
                {
                    res.push_back(i);
                    while (par[k] != k)
                    {
                        res.push_back(k);
                        k = par[k];
                    }
                    res.push_back(k);
                    cout << res.size() << endl;
                    for (int j = res.size() - 1; j >= 0; j--)
                        cout << res[j] << " ";
                    cout << endl;
                    return 0;
                }
                q.push(i);
                vis[i] = 1;
                par[i] = k;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}