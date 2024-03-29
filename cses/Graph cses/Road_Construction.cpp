#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int components;
int largest_component;
vector<int> par;
vector<int> size_of_set;
void make_Set(int v)
{
    par[v] = v;
    size_of_set[v] = 1;
}
int find_Set(int v)
{
    if (par[v] == v)
        return v;
    return par[v] = find_Set(par[v]); // path compression
}
void union_Set(int u, int v)
{
    u = find_Set(u);
    v = find_Set(v);
    if (u != v)
    {
        components--;
        if (size_of_set[v] < size_of_set[u]) // union by rank
            swap(u, v);
        par[v] = u;
        size_of_set[u] += size_of_set[v];
        largest_component = max(largest_component, size_of_set[u]);
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    size_of_set.resize(n + 1);

    for (int i = 1; i <= n; i++)
        make_Set(i);

    components = n;
    largest_component = 1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        union_Set(u, v);
        cout << components << " " << largest_component << endl;
    }
    return 0;
}