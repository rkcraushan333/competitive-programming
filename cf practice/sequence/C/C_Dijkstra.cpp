#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<int> dis(n + 1, 1e18), par(n + 1);
    for (int i = 0; i <= n; i++)
        par[i] = i;
    dis[1] = 0;
    set<pair<int, int>> s;
    s.insert({0, 1});
    while (s.size())
    {
        auto t = *s.begin();
        s.erase(s.begin());
        for (auto i : adj[t.second])
        {
            int node = i.first;
            int wt = i.second;
            if (dis[node] > dis[t.second] + wt)
            {
                par[node] = t.second;
                dis[node] = dis[t.second] + wt;
                s.insert({dis[node], node});
            }
        }
    }
    if (par[n] == n)
    {
        cout << -1;
        return 0;
    }
    vector<int> res;
    res.push_back(n);
    while (par[n] != n)
    {
        res.push_back(par[n]);
        n = par[n];
    }
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i]
             << " ";
    return 0;
}