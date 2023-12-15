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
int inv(int n)
{
    return fastexpo(n, mod - 2, mod);
}
int ncr(int n, int r)
{
    if (r > n)
        return 0;
    // on factorial fun from main
    int a = fac[n];
    int b = (fac[r] * fac[n - r]) % mod;
    int b1 = inv(b);
    return (a * b1) % mod;
}

// for inverse modulo (k^mod-2)%mod
// by inforkc

int dp[101][6][6][6][6][6];
int f(vector<vector<int>> &v, int n, int k, int a, int b, int c, int d, int e, int i = 0)
{
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
    {
        return 0;
    }
    if (i == v.size())
        return 1e13;

    int &rkc = dp[i][a][b][c][d][e];
    if (rkc != -1)
        return rkc;
    // Not Taking
    int ans = 1e14;
    ans = min(ans, f(v, n, k, a, b, c, d, e, i + 1));
    // Taking
    for (int x = 1; x < v[i].size(); x++)
    {
        if (x == 1)
        {
            a -= v[i][x];
            if (a < 0)
                a = 0;
        }
        else if (x == 2)
        {
            b -= v[i][x];
            if (b < 0)
                b = 0;
        }
        else if (x == 3)
        {
            c -= v[i][x];
            if (c < 0)
                c = 0;
        }
        else if (x == 4)
        {
            d -= v[i][x];
            if (d < 0)
                d = 0;
        }
        else if (x == 5)
        {
            e -= v[i][x];
            if (e < 0)
                e = 0;
        }
    }
    ans = min(ans, v[i][0] + f(v, n, k, a, b, c, d, e, i + 1));
    return rkc = ans;
}
void inforkc()
{
    memset(dp, -1, sizeof(dp));
    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<int>> v(n, vector<int>(k + 1));
    forn(i, 0, n)
    {
        forn(j, 0, k + 1)
        {
            cin >> v[i][j];
        }
    }
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    v64 v1(5, p);
    forn(i, 0, k)
    {
        if (i == 0)
        {
            a = v1[i];
        }
        else if (i == 1)
            b = v1[i];
        else if (i == 2)
            c = v1[i];
        else if (i == 3)
            d = v1[i];
        else if (i == 4)
            e = v1[i];
    }
    int ans = f(v, n, k, a, b, c, d, e);
    if (ans > 1e11)
        ans = -1;
    cout << ans;
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
        inforkc();
    }
    return 0;
}