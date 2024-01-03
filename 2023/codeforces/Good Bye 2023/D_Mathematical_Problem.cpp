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
#define mp map<int, int>
#define st set<int>
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
void change(string &s, string &t)
{
    char a = s[s.size() - 1], b = t[t.size() - 1];
    s[s.size() - 1] = '0';
    t[t.size() - 1] = '0';
    s += a;
    t += b;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    a = s[s.size() - 1], b = t[t.size() - 1];
    s[s.size() - 1] = '0';
    t[t.size() - 1] = '0';
    s += a;
    t += b;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
}
void inforkc()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << ln;
        return;
    }
    vector<string> v;
    v.push_back("169");
    v.push_back("196");
    v.push_back("961");
    if (n == 3)
    {
        for (auto i : v)
            cout << i << ln;
        return;
    }
    n -= 3;
    while (n)
    {
        n -= 2;
        string s1 = v[0], s2 = v[v.size() - 1];
        change(s1, s2);

        v.push_back(s2);
        reverse(v.begin(), v.end());
        v.push_back(s1);
        reverse(v.begin(), v.end());
        for (int i = 1; i < v.size() - 1; i++)
        {
            v[i].push_back('0');
            v[i].push_back('0');
        }
    }
    for (auto i : v)
        cout << i << ln;
}

// 169 196 961
// 10609 16900 19600 61009 90601
// 1006009 1060900 1690000 1960000 6100900 9006001 9060100

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