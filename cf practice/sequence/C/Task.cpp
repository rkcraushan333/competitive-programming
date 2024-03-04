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
int n, k, p;
vector<vector<int>> v;
int dp[100][2000];
int f(int i = 0, int t = 0)
{
    if (t == p)
        return 0;
    if (i >= n || t > p)
        return INT_MIN;
    if (dp[i][t] != -1)
        return dp[i][t];
    int res = 0;
    res = max(res, f(i + 1, t));
    int a = 0;
    for (int idx = 0; idx < k; idx++)
    {
        a += v[i][idx];
        res = max(res, a + f(i + 1, t + idx + 1));
    }
    return dp[i][t] = res;
}
void inforkc()
{
    int a, b, c;
    memset(dp, -1, sizeof(dp));
    cin >> a >> b >> c;
    n = a;
    k = b;
    p = c;
    vector<vector<int>> v2;
    v.resize(n, vector<int>(k));
    for (int i = 0; i < n; i++)
    {
        vector<int> t;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            t.push_back(x);
        }
        v2.push_back(t);
    }
    v = v2;
    cout << f() << "\n";
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
        cout << "Case #" << i++ << ": ";
        inforkc();
    }
    return 0;
}