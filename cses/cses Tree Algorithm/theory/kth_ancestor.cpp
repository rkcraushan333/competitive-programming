#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
vector<vector<int>> table;
void createTable(vector<int> &v, int n)
{
    table.resize(20, vector<int>(n));
    for (int i = 0; i < n; i++)
        table[0][i] = v[i];
    for (int i = 1; i < 20; i++)
    {
        for (int j = 0; j < n; j++)
        {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }
}
int kthAncestor(int node, int k)
{
    int ans = node;
    for (int i = 0; i < 20; i++)
    {
        if (k & (1 << i))
        {
            ans = table[i][ans];
        }
    }
    return ans;
}
signed main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    createTable(v, n);
    int q;
    cin >> q;
    while (q--)
    {
        int node, k;
        cin >> node >> k;
        cout << kthAncestor(node, k) << endl;
    }
    return 0;
}