#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
const int mod = 1e9 + 7;
vector<pair<int, int>> pf(int n)
{
    vector<pair<int, int>> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            pair<int, int> p;
            p.first = i;
            p.second = cnt;
            ans.push_back(p);
        }
    }
    if (n > 1)
    {
        pair<int, int> p;
        p.first = n;
        p.second = 1;
        ans.push_back(p);
    }
    return ans;
}
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
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Oredered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
// by inforkc
int dp[1000001];
// int f(int n)
// {
//     if (n == 0)
//         return 1;
//     if (dp[n] != -1)
//         return dp[n];
//     int cnt = 0;
//     for (int i = 1; i <= 6; i++)
//     {
//         if (n - i >= 0)
//             cnt = (cnt % mod + f(n - i) % mod) % mod;
//         else
//             break;
//     }
//     return dp[n] = cnt % mod;
// }
void inforkc()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    // cout << f(n);
    vector<int> table(n + 1);
    table[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j > i)
                break;
            else
                table[i] = (table[i] + table[i - j]) % mod;
        }
    }
    cout << table[n];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    int t_e_s_t = 1;
    // cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}