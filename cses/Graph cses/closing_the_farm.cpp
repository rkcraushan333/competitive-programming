#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, cnt = 1;
vector<int> par;
int find_Set(int v)
{
    if (par[v] == v)
        return v;
    return par[v] = find_Set(par[v]);
}
void union_Set(int u, int v)
{
    u = find_Set(u);
    v = find_Set(v);
    if (u != v)
        par[v] = u;
}
// by inforkc
void inforkc()
{
    cin >> n >> m;
    par.resize(n + 1);
    vector<pair<int, int>> t;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        t.push_back({u, v});
    }
    vector<int> q;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        q.push_back(a);-
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (cnt == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    if (cnt == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int t_e_s_t = 1;
    // cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}