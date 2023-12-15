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
#define pi 3.14159265358979323846
#define rsz resize
#define inc(v) sort(v.begin(), v.end())
#define dec(v) sort(v.rbegin(), v.rend())
const int mod = 1e9 + 7;
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
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
    int n;
    cin >> n;
    int mn = INT64_MAX;
    v64 a(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    v64 vv;
    vv = a;
    sort(vv.begin(), vv.end());
    int mcc = 0;
    for (auto cc : vv)
    {
        mcc = max(mcc, cc);
    }
    int mxc = INT_MAX;
    for (auto cc : vv)
    {
        mxc = max(mxc, cc);
    }
    v64 v(n, -1);
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == mn)
        {
            v[i] = a[i];
            v[i + 1] = a[i];
            break;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != mn)
        {
            v[i] = a[i];
        }
        else
        {
            for (int j = i + 2; j < n; j++)
            {
                v[j] = a[j - 1];
            }
            break;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == max(v[i], v[i + 1]))
            continue;
        else
        {
            if (v[i] > a[i])
                v[i] = a[i];
            else
            {
                if (v[i + 1] > a[i])
                    v[i + 1] = a[i];
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
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