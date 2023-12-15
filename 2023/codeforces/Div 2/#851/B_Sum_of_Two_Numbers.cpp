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
#define um unordered_map
#define us unordered_set
#define pb push_back
#define ln "\n"
#define inc(v) sort(v.begin(), v.end())
#define dec(v) sort(v.rbegin(), v.rend())
const int mod = 1e9 + 7;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Oredered set functions user less_equal for multiset
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
        return (t * t);
    else
        return (a * t * t);
}

// by inforkc
int sum(int n)
{
    int res = 0;
    while (n)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}
int cnt(int n)
{
    int res = 0;
    while (n)
    {
        n /= 10;
        res++;
    }
    return res;
}
int gen(int n)
{
    int res = 0;
    while (n)
    {
        for (int i = 9; i >= 0; i--)
        {
            if (n >= i)
            {
                res = res * 10 + i;
                n -= i;
                break;
            }
        }
    }
    return res;
}
void inforkc()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2 << endl;
        return;
    }
    else
    {
        int a = n / 2;
        if (abs(sum(a) - sum(a + 1)) <= 1)
        {
            cout << a + 1 << " " << a << endl;
            return;
        }
        int t = sum(n / 2);
        int t2 = sum(n / 2 + 1);
        int dif = abs(t - t2);
        int s = dif / 2;
        cout << n / 2 + gen(s) + 1 << " " << n / 2 - gen(s) << ln;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int t_e_s_t;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}