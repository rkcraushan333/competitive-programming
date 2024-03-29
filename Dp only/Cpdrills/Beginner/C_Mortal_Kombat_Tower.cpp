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
#define rsz resize
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
int f(int n, vector<int> &v, vector<vector<int>> &dp, int i = 0, bool t = 1)
{
    if (i == n)
        return 0;
    if (dp[i][t] != -1)
        return dp[i][t];
    if (t)
    {
        if (i < n - 1)
        {
            bool a = v[i], b = v[i + 1];
            if (a & b)
            {
                return dp[i][t] = min(1 + f(n, v, dp, i + 1, 0), 2 + f(n, v, dp, i + 2, 0));
            }
            else if (b)
            {
                return dp[i][t] = min(f(n, v, dp, i + 1, 0), 1 + f(n, v, dp, i + 2, 0));
            }
            else if (a)
            {
                return dp[i][t] = min(1 + f(n, v, dp, i + 1, 0), 1 + f(n, v, dp, i + 2, 0));
            }
            else
                return dp[i][t] = min(f(n, v, dp, i + 1, 0), f(n, v, dp, i + 2, 0));
        }
        else
        {
            if (v[i])
            {
                return dp[i][t] = 1 + f(n, v, dp, i + 1, 0);
            }
            else
            {
                return dp[i][t] = f(n, v, dp, i + 1, 0);
            }
        }
    }
    else
    {
        if (i < n - 1)
        {
            return dp[i][t] = min(f(n, v, dp, i + 1, 1), f(n, v, dp, i + 2, 1));
        }
        else
            return dp[i][t] = f(n, v, dp, i + 1, 1);
    }
}
void inforkc()
{
    int n;
    cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    cout << f(n, v, dp) << ln;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t_e_s_t = 1;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}