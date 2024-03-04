#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int n, a, b, c;
int dp[4001];
int f(int i = n)
{
    if (i == 0)
        return 0;
    int x = INT_MIN, y = INT_MIN, z = INT_MIN;
    if (dp[i] != -1)
        return dp[i];
    if (i >= a)
        x = 1 + f(i - a);
    if (i >= b)
        y = 1 + f(i - b);
    if (i >= c)
        z = 1 + f(i - c);
    return dp[i] = max(x, max(y, z));
}
signed main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> a >> b >> c;
    cout << f();
    return 0;
}