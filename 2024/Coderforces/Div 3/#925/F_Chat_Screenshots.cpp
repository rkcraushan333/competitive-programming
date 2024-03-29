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
void inforkc()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    vector<v64> v;
    forn(j, 0, k)
    {
        v64 v1;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            v1.push_back(t);
        }
        v.push_back(v1);
    }
    if (n == 1 || n == 2)
    {
        cout << "YES" << ln;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        mp[v[0][i]] = i * 2;
    }
    bool verified = 0;
    int id;
    forn(i, 1, k)
    {
        forn(j, 1, n)
        {
            if (mp.count(v[i][j]))
            {
                if (j > 1)
                {
                    if (mp[v[i][j - 1]] > mp[v[i][j]])
                    {
                        cout << "NO" << ln;
                        return;
                    }
                    else if (mp[v[i][j - 1]] == mp[v[i][j]])
                    {
                        int xx = mp[v[i][j]];
                        mp[v[i][j - 1]] = xx - 1;
                        verified = 1;
                        break;
                    }
                }
            }
            else
            {
                if (j > 1)
                {
                    mp[v[i][j]] = mp[v[i][j - 1]];
                }
                else
                {
                    mp[v[i][j]] = mp[v[i][j + 1]];
                }
            }
        }
        if (verified)
        {
            id = i;
            break;
        }
    }
    if (verified)
    {
        forn(i, id, k)
        {
            forn(j, 2, n)
            {
                if (mp[v[i][j - 1]] > mp[v[i][j]])
                {
                    cout << "NO" << ln;
                    return;
                }
            }
        }
    }
    cout << "YES" << ln;
    // error hoga isme kyoki jab koi value bich se uth ke aage jayegi ex: 5 first pe hai jo 1 and 3 ke bich me aana chahiye and 1 ka val 4, 5 ka val 6 but jab 3 ke liye val create krenge to o 4 bn jayega jo ki galat tarike se kam krega -> a/c to value = 1,3/3,1 ,  5 but original is -> 1 5 3
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