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

vector<int> st, lzst, v;
void build(int start, int end, int node = 1)
{
    if (start == end)
    {
        st[node] = v[start];
        return;
    }
    int mid = (start + end) >> 1;
    build(start, mid, 2 * node);
    build(mid + 1, end, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1];
}
void update(int start, int end, int l, int r, int val, int node = 1)
{
    if (lzst[node])
    {
        st[node] += (end - start + 1) * lzst[node];
        if (start != end)
        {
            lzst[2 * node] += lzst[node];
            lzst[2 * node + 1] += lzst[node];
        }
        lzst[node] = 0;
    }
    if (l > end || r < start)
        return;
    if (l <= start && r >= end)
    {
        if (start != end)
        {
            lzst[2 * node] += val;
            lzst[2 * node + 1] += val;
        }
        st[node] += (end - start + 1) * val;
        return;
    }
    int mid = (start + end) >> 1;
    update(start, mid, l, r, val, 2 * node);
    update(mid + 1, end, l, r, val, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1];
}
int query(int start, int end, int l, int r, int node = 1)
{
    if (lzst[node])
    {
        st[node] += (end - start + 1) * lzst[node];
        if (start != end)
        {
            lzst[2 * node] += lzst[node];
            lzst[2 * node + 1] += lzst[node];
        }
        lzst[node] = 0;
    }
    if (l > end || r < start)
    {
        return 0;
    }
    if (l <= start && r >= end)
    {
        return st[node];
    }
    int mid = (start + end) >> 1;
    int left = query(start, mid, l, r, 2 * node);
    int right = query(mid + 1, end, l, r, 2 * node + 1);
    return left + right;
}
void inforkc()
{
    int n, q;
    cin >> n >> q;
    v.resize(n);
    st.resize(4 * n);
    lzst.resize(4 * n);
    forn(i, 0, n) cin >> v[i];
    build(0, n - 1);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            update(0, n - 1, a, b, c);
        }
        else
        {
            int a;
            cin >> a;
            a--;
            cout << query(0, n - 1, a, a) << endl;
        }
    }
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