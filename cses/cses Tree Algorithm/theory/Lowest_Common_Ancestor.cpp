#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
const int mod = 1e9 + 7;
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return (t * t);
    else
        return (a * t * t);
}
// by inforkc
void dfs(int s, vector<int> &level, vector<int> &par, vector<vector<int>> &adj, int p = -1, int lev = 1)
{
    par[s] = p;
    level[s] = lev;
    for (auto child : adj[s])
    {
        if (child != p)
        {
            dfs(child, level, par, adj, s, lev + 1);
        }
    }
}

void createTable(int n, vec &par, vector<vec> &table)
{
    for (int i = 1; i <= n; i++)
    {
        table[0][i] = par[i];
    }
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (table[i - 1][j] == -1)
                table[i][j] = -1;
            else
                table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }
}

int lca(int u, int v, vector<int> &level, vector<int> &par, vector<vec> &table)
{
    if (level[u] > level[v])
        swap(u, v);

    // while (level[u] != level[v])
    // {
    //     v = par[v];
    // } using O(n)

    // Now using log(n)
    // level[v]>level[u]
    int k = level[v] - level[u];
    for (int i = 9; i >= 0; i--)
    {
        int mask = (1 << i);
        if (mask & k)
        {
            v = table[i][v];
        }
    }

    if (u == v)
        return u;
    // while (u != v)
    // {
    //     u = par[u];
    //     v = par[v];
    // }using O(n)

    // Now using log(n)
    for (int i = 9; i >= 0; i--)
    {
        int up = table[i][u];
        int vp = table[i][v];
        if (up != vp)
        {
            u = up;
            v = vp;
        }
    }
    return par[u];
}
void inforkc()
{
    int n;
    cin >> n;
    vector<int> par(n + 1), level(n + 1);
    vector<vec> adj(n + 1);
    vector<vec> table(10, vec(n + 1));
    for (int i = 0; i < n; i++)
    {
        int cnt;
        cin >> cnt;
        while (cnt--)
        {
            int a;
            cin >> a;
            adj[a].push_back(i + 1);
            adj[i + 1].push_back(a);
        }
    }
    dfs(1, level, par, adj);
    createTable(n, par, table);
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v, level, par, table) << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t_e_s_t;
    cin >> t_e_s_t;
    int i = 1;
    while (i <= t_e_s_t)
    {
        cout << "Case " << i++ << ": " << endl;
        inforkc();
    }
    return 0;
}