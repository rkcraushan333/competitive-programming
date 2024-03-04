// फल की चिंता मत करो बालक, बस करते जाओ ||
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
// by inforkc => don't use hashing in codeforces instead use set and map
void build(vp64 &st, v64 &v, int s, int e, int node)
{
    if (s == e)
    {
        st[node] = {v[s], s};
        return;
    }
    int mid = (s + e) >> 1;
    int l = 2 * node, r = 2 * node + 1;
    build(st, v, s, mid, l);
    build(st, v, mid + 1, e, r);
    if (st[l].first >= st[r].first)
    {
        st[node] = st[l];
    }
    else
    {
        st[node] = st[r];
    }
}
void update(vp64 &st, v64 &lzst, int start, int end, int l, int r, int val, int node = 1)
{
    if (l > end || r < start)
    {
        return;
    }
    if (l <= start && r >= end)
    {
        lzst[node] += val;
        return;
    }

    if (lzst[node] != 0)
    {
        if (start != end)
        {
            lzst[2 * node] += lzst[node];
            lzst[2 * node + 1] += lzst[node];
        }
        else
        {
            st[node].first += lzst[node];
        }
        lzst[node] = 0;
    }
    int mid = (start + end) >> 1;
    update(st, lzst, start, mid, l, r, val, 2 * node);
    update(st, lzst, mid + 1, end, l, r, val, 2 * node + 1);
    int l1 = 2 * node, r1 = 2 * node + 1;
    if (st[l1].first >= st[r1].first)
    {
        st[node] = st[l1];
    }
    else
    {
        st[node] = st[r1];
    }
}
pair<int, int> query(vp64 &st, v64 &lzst, int start, int end, int i, int node)
{
    if (i > end || i < start)
    {
        return {0, 0};
    }
    if (lzst[node] != 0)
    {
        lzst[2 * node] += lzst[node];
        lzst[2 * node + 1] += lzst[node];
        lzst[node] = 0;
    }
    int mid = (start + end) >> 1;
    int l = 2 * node, r = 2 * node + 1;
}

void inforkc()
{
    int n;
    cin >> n;
    v64 v(n);
    forn(i, 1, n + 1)
    {
        cin >> v[i];
        v[i] += i;
    }
    vp64 st(4 * n); // max with lowest index
    v64 lzst(4 * n);
    build(st, v, 0, n - 1, 1);
    set<int> st;
    forn(i, 0, n)
    {
        auto t = query(st, lzst, 0, n - 1, 1);
        st.insert(t.first);
        update(st, lzst, 0, n - 1, 1, t.second, t.second, -t.first);
        update(st, lzst, 0, n - 1, 1, t.second, n - 1, -1);
    }
    v64 ans;
    for (auto i : st)
        ans.push_back(i);
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
    cout << ln;
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
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}