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
#define pi 3.14159265358979323846
#define rsz resize
#define inc(v) sort(v.begin(), v.end())
#define dec(v) sort(v.rbegin(), v.rend())
const int mod = 998244353;
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return t * t;
    else
        return a * (t * t);
}

// by inforkc
int f(v64 &v, int n, int k, vector<v64> &dp, int i = 0)
{
    if (k == 0)
        return 1;
    if (i == n)
        return 0;
    int &t = dp[i][k];
    if (t != -1)
        return t;
    int res = 0;
    res += v[i] * f(v, n, k - 1, dp, i + 1);
    res %= mod;
    res += f(v, n, k, dp, i + 1);
    res %= mod;
    return t = res;
}
void inforkc()
{
    int n, k;
    cin >> n >> k;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    cout << f(v, n, k, dp);
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