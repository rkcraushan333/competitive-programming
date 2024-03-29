#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define v64 vector<int>
#define vp64 vector<pair<int, int>>
#define p64 pair<int, int>
#define forn(i, a, b) for (int i = a; i < b; i++)
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define pqmax priority_queue<int>
#define um unordered_map<int, int>
#define us unordered_set<int>
#define pb push_back
#define ln "\n"
#define inc(v) sort(v.begin(), v.end())
#define dec(v) sort(v.rbegin(), v.rend())
const int mod = 1e9 + 7;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
vp64 pf(int n)
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
        return (t * t) % mod;
    else
        return (a * (t * t) % mod) % mod;
}

// by inforkc
// int dp[11][5];
// int f(v64 &h, v64 &s, int x, int i = 0)
// {
//     if (i == h.size())
//         return 0;
//     int &t = dp[x][i];
//     if (t != -1)
//         return t;
//     int ans = 0;
//     int c = f(h, s, x, i + 1);
//     ans = max(ans, c);
//     if (x >= h[i])
//     {
//         int t = s[i] + f(h, s, x - h[i], i + 1);
//         ans = max(ans, t);
//     }
//     return t = ans;
// }
void inforkc()
{
    // memset(dp, -1, sizeof(dp));
    int n, x;
    cin >> n >> x;
    v64 h(n), s(n);
    forn(i, 0, n) cin >> h[i];
    forn(i, 0, n) cin >> s[i];
    // cout << f(h, s, x);
    vector<int> dp(x + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= 1; j--)
        {
            if (j >= h[i - 1])
            {
                dp[j] = max(dp[j], dp[j - h[i - 1]] + s[i - 1]);
            }
        }
    }
    cout << dp[x];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t_e_s_t = 1;
    // cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}