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

vector<int> par;
vector<int> Size;
void make_Set(int v)
{
    par[v] = v;
    Size[v] = 1;
}
int find_Set(int v)
{
    return par[v] = (par[v] == v) ? v : find_Set(par[v]);
}
void union_Set(int u, int v)
{
    u = find_Set(u);
    v = find_Set(v);
    if (u != v)
    {
        if (Size[u] < Size[v])
            swap(u, v);
        par[v] = u;
        Size[u] += Size[v];
    }
}

// by inforkc
void inforkc()
{
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    if (s == t)
    {
        cout << "YES" << ln;
        return;
    }
    string s1 = s, t1 = t;
    sort(s1.begin(), s1.end());
    sort(t1.begin(), t1.end());
    if (n >= 6)
    {
        if (s1 == t1)
        {
            cout << "YES" << ln;
        }
        else
        {
            cout << "NO" << ln;
        }
    }
    else
    {
        if (n == 5)
        {
            if (s[2] == t[2])
            {
                set<char> s1, s2;
                s1.insert(s[0]);
                s1.insert(s[1]);
                s1.insert(s[4]);
                s1.insert(s[3]);
                s2.insert(t[0]);
                s2.insert(t[1]);
                s2.insert(t[4]);
                s2.insert(t[3]);
                if (s1 == s2)
                {
                    cout << "YES" << endl;
                }
                else
                    cout << "NO" << endl;
            }
            else
                cout << "NO" << ln;
        }
        if (n == 4)
        {
            if (s[1] == t[1] && s[2] == t[2])
            {
                set<char> s1, s2;
                s1.insert(s[0]);
                s1.insert(s[3]);
                s2.insert(t[0]);
                s2.insert(t[3]);
                if (s1 == s2)
                {
                    cout << "YES" << endl;
                }
                else
                    cout << "NO" << endl;
            }
            else
                cout << "NO" << endl;
        }
        if (n < 4)
        {
            cout << "NO" << ln;
        }
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