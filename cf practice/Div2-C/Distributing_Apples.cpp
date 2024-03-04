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
int mpw(int base, int exp, int M)
{ // O(LOGEXP) TIME
    if (exp == 0)
        return 1;
    int res = mpw(base, exp / 2, M);
    if (exp % 2 == 1)
        return (((res * res) % M) * base) % M;
    else
        return (res * res) % M;
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
// int dp[1000001];
// int fac(int a)
// {
//     if (a == 0 || a == 1)
//         return 1;
//     if (dp[a] != -1)
//         return dp[a];
//     return dp[a] = (a * fac(a - 1)) % mod;
//
int F[1000001];
void ix()
{
    F[0] = F[1] = 1;
    for (int i = 2; i <= 1000000; i++)
        F[i] = (F[i - 1] * 1LL * i) % mod;
}

void inforkc()
{
    // memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> m >> n;
    int a = F[n + m - 1] % mod;
    int b = F[n] % mod;
    int c = F[m - 1] % mod;
    // cout << a << " " << b << " " << c << endl;
    b = (b * c) % mod;
    b = mpw(b, mod - 2, mod) % mod;
    a *= b;
    a %= mod;
    cout << a << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t_e_s_t = 1;
    ix();
    // cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}