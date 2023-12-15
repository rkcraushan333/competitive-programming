#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
vector<int> par;
vector<int> Size;
void make_Set(int v)
{
    par[v] = v;
    Size[v] = 1;
}
int find_Set(int v)
{
    return par[v] = (par[v] == v) ? v : find_Set(par[v]);
}
void union_Set(int u, int v)
{
    if (Size[u] < Size[v])
        swap(u, v);
    par[v] = u;
    Size[u] += Size[v];
}
signed main()
{

    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    Size.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        make_Set(i);
    }
    int res = 0;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a = find_Set(a);
        b = find_Set(b);
        if (a == b)
            res++;
        else
            union_Set(a, b);
    }
    cout << res << endl;
    return 0;
}