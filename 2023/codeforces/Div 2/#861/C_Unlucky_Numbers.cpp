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
int res(int n)
{
    int a = INT_MAX, b = 0;
    while (n)
    {
        a = min(a, n % 10);
        b = max(b, n % 10);
        n /= 10;
    }
    return b - a;
}
int s(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}
void inforkc()
{
    int l, r;
    cin >> l >> r;
    int r1 = r;
    if (l == r)
    {
        cout << l << ln;
        return;
    }
    if (s(r) > s(l))
    {
        int cnt = s(l);
        while (cnt--)
        {
            cout << 9;
        }
        cout << ln;
        return;
    }
    if ((l / 10) < (r / 10) - 1)
    {
        int k = l;
        while (s(k) > 1)
        {
            k /= 10;
        }
        int cnt = s(l);
        while (cnt--)
        {
            cout << k + 1;
        }
        cout << ln;
        return;
    }
    string s = to_string(l), t = to_string(r);
    if (s[0] == t[0])
    {
        string ss = "";
        int cnt = s.size();
        while (cnt--)
        {
            ss += s[0];
        }
        if (ss <= t)
        {
            cout << stoi(ss) << ln;
        }
        else
            cout << stoi(s) << ln;
        return;
    }
    int cnt = s.size();
    string ss = "";
    while (cnt--)
    {
        ss += s[0];
    }
    if (ss >= s)
    {
        cout << stoi(ss);
        return;
    }
    cnt = s.size();
    ss = "";
    while (cnt--)
    {
        ss += t[0];
    }
    if (ss <= t)
    {
        cout << stoi(ss);
        return;
    }
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