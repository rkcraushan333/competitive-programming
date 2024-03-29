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
#define yy cout << "Yes" << ln
#define nn cout << "No" << ln
#define pi 3.14159265358979323846
#define rsz resize
#define inc(v) sort(v.begin(), v.end())
#define dec(v) sort(v.rbegin(), v.rend())
const int mod = 1e9 + 7;
#define dbg cout << "debug" << ln;
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
int fac[1000001];
void factorial()
{
    fac[0] = fac[1] = 1;
    forn(i, 2, 1000001)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
}
int pows[1000001];
bool done = 0;
int power10(int n)
{
    if (!done)
    {
        pows[0] = 1;
        for (int i = 1; i <= 1000000; i++)
            pows[i] = (pows[i - 1] * 10LL) % mod;
        done = 1;
    }
    return pows[n];
}
vector<int> prime;
void sieve()
{
    prime.resize(1e6 + 1);
    for (int i = 0; i < prime.size(); i++)
    {
        prime[i] = i;
    }
    for (int i = 2; i <= 1e6; i++)
    {
        if (prime[i] == i)
        {
            for (int j = 2 * i; j <= 1e6; j += i)
            {
                prime[j] = i;
            }
        }
    }
}
v64 primefac(int n)
{
    v64 res;
    while (n != prime[n])
    {
        res.push_back(prime[n]);
        n /= prime[n];
    }
    if (n != 1)
        res.push_back(n);
    return res;
}
int fastexpo(int a, int b, int m)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
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

// for inverse modulo (k^mod-2)%mod
// by inforkc
int dp[5001][5001];
int f(string &s, string &t, int i = 0, int j = 0)
{
    if (i == s.size())
    {
        return t.size() - j;
    }
    if (j == t.size())
    {
        return s.size() - i;
    }
    int &rkc = dp[i][j];
    if (rkc != -1)
        return rkc;
    int ans = INT_MAX;
    if (s[i] == t[j])
    {
        // if both char are same
        ans = min(ans, f(s, t, i + 1, j + 1));
    }
    else
    {
        // if both are not same
        // 1. removing from 1st string or adding to string2
        ans = min(ans, 1 + f(s, t, i + 1, j));
        // 2. removing from 2nd string or adding to string1
        ans = min(ans, 1 + f(s, t, i, j + 1));
        // 3. replacing int any string to make the both char equal
        ans = min(ans, 1 + f(s, t, i + 1, j + 1));
    }
    return rkc = ans;
}
void inforkc()
{
    string s, t;
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    cout << f(s, t);
}
void iterative()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<v64> t(n + 1, v64(m + 1, INT_MAX));
    t[0][0] = 0;
    for (int i = 1; i <= n; i++)
        t[i][0] = i;
    for (int i = 1; i <= m; i++)
        t[0][i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                t[i][j] = min(t[i][j], t[i - 1][j - 1]);
            }
            else
            {
                t[i][j] = min({t[i][j], t[i - 1][j - 1] + 1, 1 + t[i - 1][j], 1 + t[i][j - 1]});
            }
        }
    }
    cout << t[n][m];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // sieve();
    // factorial();
    int t_e_s_t = 1;
    // cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        // inforkc();
        iterative();
    }
    return 0;
}