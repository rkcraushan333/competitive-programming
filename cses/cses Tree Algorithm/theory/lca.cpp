#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
vector<int> par;
void dfs(vector<vector<int>> &adj, int s = 1, int p = -1)
{
    par[s] = p;
    for (auto i : adj[s])
    {
        if (i != p)
            dfs(adj, i, s);
    }
}
vector<int> f(int s)
{
    vector<int> v;
    while (s != -1)
    {
        v.push_back(s);
        s = par[s];
    }
    reverse(v.begin(), v.end());
    return v;
}
signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    par.resize(n + 1);
    dfs(adj);
    int x, y;
    cin >> x >> y;
    vector<int> v1 = f(x);
    vector<int> v2 = f(y);
    int m = min(v1.size(), v2.size());
    int ans;
    for (int i = 0; i < m; i++)
    {
        if (v1[i] != v2[i])
        {
            break;
        }
        ans = v1[i];
    }
    cout << ans;
    return 0;
}