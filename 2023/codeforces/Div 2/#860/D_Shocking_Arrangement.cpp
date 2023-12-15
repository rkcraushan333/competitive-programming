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
    v64 v(n);
    int mx = INT_MIN, mn = INT_MAX;
    multiset<int> ss1, ss2;
    forn(i, 0, n)
    {
        cin >> v[i];
        mx = max(v[i], mx);
        mn = min(v[i], mn);
        if (v[i] >= 0)
            ss1.insert(v[i]);
        else
            ss2.insert(v[i]);
    }
    v64 s1, s2;
    for (auto i : ss1)
    {
        s1.push_back(i);
    }
    for (auto i : ss2)
    {
        s2.push_back(i);
    }
    int t = mx - mn;
    for (auto i : v)
    {
        if (i >= t)
        {
            cout << "No" << ln;
            return;
        }
    }
    cout << "Yes" << ln;
    int i = 0, j = 0;
    int res = 0;
    v64 ans;
    while (i < s1.size() && j < s2.size())
    {

        if (res + s1[i] >= t)
        {
            res += s2[j];
            ans.push_back(s2[j]);
            j++;
        }
        else
        {
            res += s1[i];
            ans.push_back(s1[i]);
            i++;
        }
    }
    while (i < s1.size())
    {
        ans.push_back(s1[i]);
        i++;
    }
    while (j < s2.size())
    {
        ans.push_back(s2[j]);
        j++;
    }
    for (auto i : ans)
    {
        cout << i << " ";
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