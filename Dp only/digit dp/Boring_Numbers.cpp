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
int dp[19][2][2][2];
int f(string &s, int idx = 0, bool tight = 1, bool parity = 1, bool lz = 1)
{
    if (idx == s.size())
    {
        if (lz)
            return 0;
        return 1;
    }
    int &t = dp[idx][tight][parity][lz];
    if (t != -1)
        return t;
    int limit = tight ? s[idx] - '0' : 9;
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        if (i == 0)
        {
            if (lz)
                ans += f(s, idx + 1, tight & (limit == i), parity, lz);

            else if (parity % 2 == 0)
                ans += f(s, idx + 1, tight & (limit == i), !parity, lz);
        }

        else if (parity)
        {
            if (!lz)
            {
                if (i & 1)
                    ans += f(s, idx + 1, tight & (limit == i), !parity, lz);
            }
            else
            {
                if (i & 1)
                    ans += f(s, idx + 1, tight & (limit == i), !parity, !lz);
            }
        }
        else
        {
            if (!lz)
            {
                if (i % 2 == 0)
                    ans += f(s, idx + 1, tight & (limit == i), !parity, lz);
            }
            else
            {
                if (i % 2 == 0)
                    ans += f(s, idx + 1, tight & (limit == i), !parity, !lz);
            }
        }
    }
    return t = ans;
}
int f1(int n)
{
    memset(dp, -1, sizeof(dp));
    if (n == 0)
        return 0;
    string s = to_string(n);
    return f(s);
}
void inforkc()
{
    int l, r;
    cin >> l >> r;
    cout << f1(r) - f1(l - 1) << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t_e_s_t = 1;
    cin >> t_e_s_t;
    int i = 1;
    while (i <= t_e_s_t)
    {
        cout << "Case #" << i++ << ": ";
        inforkc();
    }
    return 0;
}