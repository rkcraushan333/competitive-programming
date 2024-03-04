#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
vector<int> v(100001);
int dp[100001];
int f(int i = 1)
{
    if (i >= v.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    if (v[i] != 0)
        return dp[i] = max(f(i + 1), (v[i] * i) + f(i + 2));
    else
        return dp[i] = f(i + 1);
}
signed main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        v[k]++;
    }
    cout << f();
    return 0;
}