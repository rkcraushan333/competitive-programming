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
// by inforkc => don't use hashing instead use set and map
void inforkc()
{
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    int i1, j1, i2, j2, c = 0;
    forn(i, 0, n)
    {
        forn(j, 0, n)
        {
            cin >> v[i][j];
            if (v[i][j] == 'P')
            {
                if (c == 0)
                {
                    i1 = i;
                    j1 = j;
                    c = 1;
                }
                else
                {
                    i2 = i;
                    j2 = j;
                }
            }
        }
    }
    int dis[n][n][n][n] = {1e9};
    queue<vector<int>> q;
    int ans = INT64_MAX;
    q.push({i1, j1, 0});
    q.push({i2, j2, 0});
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    while (!q.empty())
    {
        auto a = q.front();
        q.pop();
        auto b = q.front();
        q.pop();
        int x1 = a[0], y1 = a[1], d1 = a[2];
        int x2 = b[0], y2 = b[1], d2 = b[2];
        if (x1 == x2 && y1 == y2)
        {
            dis[x1][y1][x2][y2] = max(d1, d1);
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
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}