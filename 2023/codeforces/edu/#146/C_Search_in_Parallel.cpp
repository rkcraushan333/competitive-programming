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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    v64 v1, v2;
    vp64 v;
    forn(i, 0, n)
    {
        int t;
        cin >> t;
        v.push_back({t, i + 1});
    }
    sort(v.rbegin(), v.rend());
    int c = 1;
    int i = 1, j = 1;
    while (c <= n)
    {
        if (i * s1 * v[c - 1].first <= j * s2 * v[c - 1].first)
        {
            v1.push_back(v[c - 1].second);
            i++;
        }
        else
        {
            v2.push_back(v[c - 1].second);
            j++;
        }
        c++;
    }
    cout << v1.size() << " ";
    for (auto ii : v1)
        cout << ii << " ";
    cout << ln;
    cout << v2.size() << " ";
    for (auto ii : v2)
        cout << ii << " ";
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