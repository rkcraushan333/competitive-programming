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
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
vector<bool> prime;
void sieve()
{
    prime.resize(1e6 + 1, 1);
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i <= 1e6; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= 1e6; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
vector<int> pfactor;
void psieve()
{
    pfactor.resize(1e6 + 1);
    for (int i = 0; i < pfactor.size(); i++)
    {
        pfactor[i] = i;
    }
    for (int i = 2; i <= 1e6; i++)
    {
        if (pfactor[i] == i)
        {
            for (int j = 2 * i; j <= 1e6; j += i)
            {
                pfactor[j] = i;
            }
        }
    }
}
v64 primefac(int n)
{
    v64 res;
    while (n != pfactor[n])
    {
        res.push_back(pfactor[n]);
        n /= pfactor[n];
    }
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

// by inforkc
void inforkc()
{
    int n, x;
    cin >> n >> x;
    v64 v(n);
    int t = 0;
    forn(i, 0, n)
    {
        cin >> v[i];
        t = __gcd(t, v[i]);
    }
    set<int> s;
    for (auto i : v)
        s.insert(i);
    if (s.size() == 1)
    {
        cout << 0 << ln;
        return;
    }
    if (t >= 2)
    {
        cout << 1 << ln;
        cout << t << ln;
        return;
    }
    int cnt = 0;
    for (auto i : v)
    {
        if (i & 1)
            cnt++;
    }
    if (cnt == n)
    {
        cout << 1 << ln;
        cout << 2 << ln;
        return;
    }
    set<int> st;
    for (auto i : v)
    {
        v64 kk = primefac(i);
        for (auto j : kk)
        {
            st.insert(j);
        }
    }
    forn(i, 2, x + 1)
    {
        if (prime[i])
            if (st.find(i) == st.end())
            {
                cout << 1 << ln;
                cout << i << ln;
                return;
            }
    }
    cout << 2 << ln;
    cout << x << " " << x - 1 << ln;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    sieve();
    psieve();
    int t_e_s_t = 1;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}