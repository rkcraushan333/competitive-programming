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
#define rsz resize
#define inc(v) sort(v.begin(), v.end())
#define dec(v) sort(v.rbegin(), v.rend())
const int mod = 1e9 + 7;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
vp64 pf(int n)
{
    vector<pair<int, int>> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            pair<int, int> p;
            p.first = i;
            p.second = cnt;
            ans.push_back(p);
        }
    }
    if (n > 1)
    {
        pair<int, int> p;
        p.first = n;
        p.second = 1;
        ans.push_back(p);
    }
    return ans;
}
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return (t * t) % mod;
    else
        return (a * (t * t) % mod) % mod;
}

// by inforkc
void inforkc()
{
    int n;
    cin >> n;
    v64 v1(n), v2(n), v3(n), v4(n);
    forn(i, 0, n) cin >> v1[i];
    forn(i, 0, n) cin >> v2[i];
    v3 = v2;
    v4 = v2;
    for (int i = n - 2; i >= 0; i--)
    {
        v2[i] += v2[i + 1];
    }
    forn(i, 1, n)
    {
        v3[i] += v3[i - 1];
    }
    v64 v(n + 1, 0), x(n + 1, 0);
    map<int, int> m;
    forn(i, 0, n)
    {
        if (v1[i] >= v2[i])
        {
            v[i]++;
        }
        else
        {
            if (v1[i] <= v4[i])
            {
                m[i] += v1[i];
            }
            else
            {
                int t = lower_bound(v3.begin() + i, v3.end(), v1[i]) - v3.begin();
                x[t]--;
                x[i]++;
                if (i > 0)
                    m[t] += v1[i] - (v3[t - 1] - v3[i - 1]);
                else
                    m[t] += v1[i] - v3[t - 1];
            }
        }
    }

    // for (int i = n - 2; i >= 0; i--)
    // {
    // }
    for (int i = 1; i < n; i++)
    {
        x[i] += x[i - 1];
        v[i] += v[i - 1];
    }
    // for (auto i : x)
    // {
    //     cout << i << " ";
    // }
    // cout << ln;
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << ln;
    // for (auto i : m)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    v64 res(n);
    for (int i = 0; i < n; i++)
    {
        cout << ((x[i] + v[i]) * v4[i]) + m[i] << " ";
    }
    cout << ln;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t_e_s_t = 1;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}