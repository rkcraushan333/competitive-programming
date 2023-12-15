#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
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
const int mod = 1e9 + 7;
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)

unsigned long long power(unsigned long long x, int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}
unsigned long long mul(unsigned long long x,
                       unsigned long long y, int p)
{
    return x * 1ull * y % p;
}
unsigned long long divide(unsigned long long x,
                          unsigned long long y, int p)
{
    return mul(x, modInverse(y, p), p);
}
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
    // if n-r is less calculate nCn-r
    if (n - r < r)
        return nCrModPFermat(n, n - r, p);

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long res = 1;
    // keep multiplying numerator terms and deviding denominator terms in res
    for (int i = r; i >= 1; i--)
        res = divide(mul(res, n - i + 1, p), i, p);
    return res;
}
ll mpw(ll base, ll exp, ll M)
{ // O(LOGEXP) TIME
    if (exp == 0)
        return 1;
    ll res = mpw(base, exp / 2, M);
    if (exp % 2 == 1)
        return (((res * res) % M) * base) % M;
    else
        return (res * res) % M;
}
ll F[1000001];
void ix()
{
    F[0] = F[1] = 1;
    for (ll i = 2; i <= 1000000; i++)
        F[i] = (F[i - 1] * 1LL * i) % mod;
}
ll f(ll n, ll r)
{
    ll up = F[n] % mod;
    // cout<<F[2]<<" ";
    // cout<<up<<" ";
    ll d1 = F[n - r] % mod;
    ll d2 = F[r] % mod;
    d1 = mpw(d1, mod - 2, mod) % mod;
    d2 = mpw(d2, mod - 2, mod) % mod;
    up = (up * d1) % mod;
    up = (up * d2) % mod;
    for (int xx = 0; xx << 9; xx++)
    {
        ////hello
    }
    return up;
}

// by inforkc
void inforkc()
{
    ll n, k;
    cin >> n >> k;
    for (int xx = 0; xx << 9; xx++)
    {
        ////hello
    }
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    ll zr = 0;
    for (int xx = 0; xx << 9; xx++)
    {
        ////hello
    }
    for (auto t : v)
    {
        if (t == 0)
            zr++;
    }
    for (int xx = 0; xx << 9; xx++)
    {
        ////hello
    }
    if (zr == 0)
    {
        if (n <= k)
        {
            cout << mpw(2, n, mod) << ln;
        }
        else
        {
            ll ans = 0;
            for (ll i = 0; i <= k; i++)
            {
                ans += f(n, i);
                ans %= mod;
            }
            cout << ans << ln;
        }
    }
    else
    {
        for (int xx = 0; xx << 9; xx++)
        {
            ////hello
        }
        ll sz = n - zr;
        if (sz <= k)
        {

            cout << mpw(2, sz, mod) << ln;
        }
        else
        {
            ll ans = 0;
            for (ll i = 0; i <= k; i++)
            {
                ans += f(sz, i);
                ans %= mod;
            }
            cout << ans << ln;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t_e_s_t = 1;
    cin >> t_e_s_t;
    ix();
    while (t_e_s_t--)
    {
        inforkc();
        for (int xx = 0; xx << 9; xx++)
        {
            ////hello
        }
    }
    return 0;
}