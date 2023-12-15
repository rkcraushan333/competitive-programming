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
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> T;
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
    int n, a, b;
    cin >> n >> a >> b;
    vp64 v;
    forn(i, 0, a + b)
    {
        int aa, bb;
        cin >> aa >> bb;
        v.push_back({aa, bb});
    }
    pair<int, int> i, j;
    int cnt = 0;
    i = {0, v[0].second};
    j = {a, v[a].second};
    while (i.first < a && j.first < a + b)
    {

        if (v[i.first].first == v[j.first].first)
        {
            if (i.second > j.second)
            {
                cnt += j.second;
                i.second -= j.second;
                if (j.first + 1 == a + b)
                    break;
                j.first++;
                j.second = v[j.first].second;
            }
            else if (i.second < j.second)
            {
                cnt += i.second;
                j.second -= i.second;
                if (i.first + 1 == a)
                    break;
                i.first++;
                i.second = v[i.first].second;
            }
            else
            {
                cnt += i.second;
                if (i.first + 1 == a)
                    break;
                i.first++;
                i.second = v[i.first].second;
                if (j.first + 1 == a + b)
                    break;
                j.first++;
                j.second = v[j.first].second;
            }
        }
        else
        {
            if (i.second > j.second)
            {
                i.second -= j.second;
                if (j.first + 1 == a + b)
                    break;
                j.first++;
                j.second = v[j.first].second;
            }
            else if (i.second < j.second)
            {
                j.second -= i.second;
                if (i.first + 1 == a)
                    break;
                i.first++;
                i.second = v[i.first].second;
            }
            else
            {
                if (i.first + 1 == a)
                    break;
                i.first++;
                i.second = v[i.first].second;
                if (j.first + 1 == a + b)
                    break;
                j.first++;
                j.second = v[j.first].second;
            }
        }
    }
    cout << cnt << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t_e_s_t = 1;
    // cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}