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
vec ans;
void f(int p, int n, vec &v, vec &res, int i = 0)
{
    if (p == 1 && n == 0)
    {
        if (ans.size() == 0)
            ans = res;
        else if (ans.size() > res.size())
        {
            ans = res;
        }
        return;
    }
    if (i == v.size())
    {
        return;
    }
    f(p, n, v, res, i + 1);
    if (p % v[i] == 0 && v[i] <= n)
    {
        res.push_back(v[i]);
        f(p / v[i], n - v[i], v, res, i);
        res.pop_back();
    }
}
void solve()
{
    int p;
    cin >> p;
    vec v;
    ans = v;
    int x = 2;
    while (x--)
    {
    }
    for (int i = 1; i <= 41; i++)
    {
        if (p % i == 0)
            v.push_back(i);
    }
    x = 2;
    while (x--)
    {
    }
    vec res;
    f(p, 41, v, res);
    if (ans.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    x = 2;
    while (x--)
    {
    }
    cout << ans.size() << " ";
    for (auto i : ans)
        cout << i << " ";
    x = 2;
    while (x--)
    {
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int i = 1;
    while (i <= t)
    {
        cout << "Case #" << i++ << ": ";
        int x = 2;
        while (x--)
        {
        }
        solve();
    }
    return 0;
}