#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define v64 vector<ll>
#define vp64 vector<pair<ll, ll>>
#define p64 pair<ll, ll>
#define forn(i, a, b) for (ll i = a; i < b; i++)
#define pqmin priority_queue<ll, vector<ll>, greater<ll>>
#define pqmax priority_queue<ll>
#define um unordered_map<ll, ll>
#define us unordered_set<ll>
#define pb push_back
#define ln "\n"
#define yy cout << "Yes" << ln
#define nn cout << "No" << ln
#define pi 3.14159265358979323846
#define rsz resize
const ll mod = 1e9 + 7;
#define dbg cout << "debug" << ln;
tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
ll fac[1000001];
void factorial()
{
    fac[0] = fac[1] = 1;
    forn(i, 2, 1000001)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
}
ll pows[1000001];
bool done = 0;
ll power10(ll n)
{
    if (!done)
    {
        pows[0] = 1;
        for (ll i = 1; i <= 1000000; i++)
            pows[i] = (pows[i - 1] * 10LL) % mod;
        done = 1;
    }
    return pows[n];
}
vector<ll> prime;
void sieve()
{
    prime.resize(1e6 + 1);
    for (ll i = 0; i < prime.size(); i++)
    {
        prime[i] = i;
    }
    for (ll i = 2; i <= 1e6; i++)
    {
        if (prime[i] == i)
        {
            for (ll j = 2 * i; j <= 1e6; j += i)
            {
                prime[j] = i;
            }
        }
    }
}
v64 primefac(ll n)
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
ll fastexpo(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll fastpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return t * t;
    else
        return a * (t * t);
}
ll inv(ll n)
{
    return fastexpo(n, mod - 2, mod);
}
ll ncr(ll n, ll r)
{
    if (r > n)
        return 0;
    // on factorial fun from main
    ll a = fac[n];
    ll b = (fac[r] * fac[n - r]) % mod;
    ll b1 = inv(b);
    return (a * b1) % mod;
}

// for inverse modulo (k^mod-2)%mod
// by inforkc
void inforkc()
{
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll dx[8] = {a, a, -a, -a, b, b, -b, -b};
    ll dy[8] = {b, -b, b, -b, a, -a, a, -a};
    set<pair<ll, ll>> st;
    for (ll i = 0; i < 8; i++)
    {
        ll x = c + dx[i];
        ll y = d + dy[i];
        st.insert({x, y});
    }
    set<pair<ll, ll>> cnt;
    for (ll i = 0; i < 8; i++)
    {
        ll x = e + dx[i];
        ll y = f + dy[i];
        if (st.count({x, y}))
        {
            cnt.insert({x, y});
        }
    }
    cout << cnt.size() << ln;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // sieve();
    // factorial();
    ll t_e_s_t = 1;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}