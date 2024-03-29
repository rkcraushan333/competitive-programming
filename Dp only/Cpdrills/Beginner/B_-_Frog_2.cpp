#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
int n, k;
vector<int> v;
int dp[100001];
int f(int i = 0)
{
    if (i == n - 1)
        return 0;
    int ans = INT_MAX;
    if (dp[i] != -1)
        return dp[i];
    for (int j = 1; j <= k; j++)
    {
        if (i + j <= n - 1)
            ans = min(ans, abs(v[j + i] - v[i]) + f(i + j));
    }
    return dp[i] = ans;
}
signed main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << f();
    return 0;
}