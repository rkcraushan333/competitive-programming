#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define v64 vector<int>
#define vp64 vector<pair<int, int>>
#define forn(i, a, b) for (int i = a; i < b; i++)
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define pqmax priority_queue<int>
#define ln "\n"
#define yy cout << "Yes" << ln
#define nn cout << "No" << ln
#define pi 3.14159265358979323846
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
// by inforkc => don't use hashing instead use set and map
int find_Set(int v, v64 &par)
{
    return par[v] = (par[v] == v) ? v : find_Set(par[v], par);
}
void union_Set(int u, int v, v64 &par, v64 &Size)
{
    u = find_Set(u, par);
    v = find_Set(v, par);
    if (u != v)
    {
        if (Size[u] < Size[v])
            swap(u, v);
        par[v] = u;
        Size[u] += Size[v];
    }
}
void inforkc()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    v64 p1(n + 1), p2(n + 1), s1(n + 1, 1), s2(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        p1[i] = i;
        p2[i] = i;
        s1[i] = 1;
        s2[i] = 1;
    }
    forn(i, 0, m1)
    {
        int u, v;
        cin >> u >> v;
        union_Set(u, v, p1, s1);
    }
    forn(i, 0, m2)
    {
        int u, v;
        cin >> u >> v;
        union_Set(u, v, p2, s2);
    }
    vp64 v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (find_Set(i, p1) != find_Set(j, p1))
            {
                if (find_Set(i, p2) != find_Set(j, p2))
                {
                    // cout << i << " " << j << ln;
                    union_Set(i, j, p1, s1);
                    union_Set(i, j, p2, s2);
                    v.push_back({i, j});
                }
            }
        }
    }

    cout << v.size() << ln;
    for (auto i : v)
    {
        cout << i.first << " " << i.second << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("filename.in", "r", stdin);
    // freopen("filename.out", "w", stdout);
    // sieve();
    // factorial();
    int t_e_s_t = 1;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}