#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
vector<int> par, Size;
int findSet(int a)
{
    return par[a] = par[a] == a ? a : findSet(par[a]);
}
void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (Size[b] > Size[a])
            swap(a, b);
        Size[a] += Size[b];
        par[b] = a;
    }
}
signed main()
{
    int n, q;
    cin >> n >> q;
    par.resize(n);
    Size.resize(n, 1);
    for (int i = 0; i < n; i++)
        par[i] = i;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a)
        {
            cout << (findSet(b) == findSet(c)) << endl;
        }
        else
        {
            unionSet(b, c);
        }
    }
    return 0;
}