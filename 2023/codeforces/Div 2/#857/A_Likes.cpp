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
    set<int> s1, s2;
    forn(i, 0, n)
    {
        int a;
        cin >> a;
        if (a > 0)
        {
            s1.insert(a);
        }
        else
            s2.insert(a);
    }
    for (auto i : s2)
    {
        if (s1.find(abs(i)) == s1.end())
        {
            s2.erase(i);
        }
    }
    int a = s1.size(), b = s2.size();
    int c = 0;
    for (int i = 0; i < a; i++)
    {
        cout << c + 1 << " ";
        c++;
    }
    for (int i = 0; i < b; i++)
    {
        cout << c - 1 << " ";
        c--;
    }
    cout << endl;
    for (int i = 0; i < 2 * b; i++)
    {
        if (i % 2 == 0)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    c = 1;
    for (int i = 2 * b; i < n; i++)
    {
        cout << c++ << " ";
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