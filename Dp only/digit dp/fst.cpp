#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int dp[101][181][2];
int f(string &s, int idx, int sum, int tight)
{
    if (sum < 0)
        return 0;
    if (idx == s.size())
    {
        if (sum == 0)
            return 1;
        return 0;
    }
    int &t = dp[idx][sum][tight];
    if (t != -1)
        return t;
    int ans = 0;
    int limit = tight ? s[idx] - '0' : 9;
    for (int i = 0; i <= limit; i++)
    {
        ans += f(s, idx + 1, sum - i, (tight & (i == limit)));
    }
    return t = ans;
}
signed main()
{
    memset(dp, -1, sizeof(dp));
    string s = "5847657503";
    cout << f(s, 0, 58, 1);
    return 0;
}