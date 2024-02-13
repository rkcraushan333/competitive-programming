// हर हर महादेव
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordred_set;
// member functions :(-- use less_equal to make it multiset)
// 1. order_of_key(k) : number of elements strictly lesser than k
// 2. find_by_order(k) : k-th element in the set
typedef priority_queue<int> mxpq;
typedef priority_queue<int, vector<int>, greater<int>> mnpq;
const int mod = 1e9 + 7;
const int mod1 = 998244353;
int fac[1000005];
void fact(int fac[])
{
    fac[0] = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        fac[i] = fac[i - 1] * i; // (a*b)%m = ((a%m)(b%m))%m
        fac[i] %= mod;
    }
}
//---------binary exponantiation----------------
int binExp(int x, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            res *= x;
            res %= mod;
        }
        n /= 2;
        x *= x;
        x %= mod;
    }
    return res;
}
//--------------ncr-------------------------------
int ncr(int n, int r)
{
    int temp1 = fac[n];
    int temp2 = fac[n - r] * fac[r];
    temp2 %= mod;
    int temp3 = binExp(temp2, mod - 2); // temp3 is the modulo inverse
    temp1 *= temp3;
    temp1 %= mod;
    return temp1;
}
void solve()
{
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    unordered_map<int, int> mpl, mpr;
    int left = 1e18;
    int right = -1e18;
    for (int i = 0; i < n; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        if (mp.count({l, r}))
            mp[{l, r}] = min(mp[{l, r}], c);
        else
            mp[{l, r}] = c;

        left = min(left, l);
        right = max(right, r);
        if (mpl.count(l))
            mpl[l] = min(mpl[l], c);
        else
            mpl[l] = c;

        if (mpr.count(r))
            mpr[r] = min(mpr[r], c);
        else
            mpr[r] = c;

        int x = 1e18;
        if (mp.count({left, right}))
            x = mp[{left, right}];

        cout << min(mpl[left] + mpr[right], x) << endl;
    }
}
int32_t main()
{
    // fact(fac);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}