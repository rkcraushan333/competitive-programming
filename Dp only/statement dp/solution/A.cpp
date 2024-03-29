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
int dp[102];
int maxClimb(int i, vector<int> &v)
{
    if (i == v.size() - 1)
        return v[i];
    if (dp[i] != -1)
        return dp[i];
    int ans = INT_MIN;
    int a = maxClimb(i + 1, v) + v[i];
    ans = max(ans, a);
    if (i < v.size() - 2)
    {
        int b = maxClimb(i + 2, v) + v[i];
        ans = max(ans, b);
    }
    return dp[i] = ans;
}
void inforkc()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << maxClimb(0, v) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
    // int t_e_s_t;
    // cin >> t_e_s_t;
    // while (t_e_s_t--)
    // {
    inforkc();
    // }
    return 0;
}