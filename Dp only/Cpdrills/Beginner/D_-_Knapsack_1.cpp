#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define v64 vector<ll>
#define p64 pair<ll, ll>
#define p64 pair<ll, ll>
const int mod = 1e9 + 7;
vector<pair<ll, ll>> pf(ll n)
{
    vector<pair<ll, ll>> ans;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            pair<ll, ll> p;
            p.first = i;
            p.second = cnt;
            ans.push_back(p);
        }
    }
    if (n > 1)
    {
        pair<ll, ll> p;
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
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Oredered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
// by inforkc
ll n;
vector<p64> v;
ll dp[100001][101];
ll f(ll w, ll i = 0)
{
    if (w == 0 || i == n)
        return 0;
    if (dp[w][i] != -1)
        return dp[w][i];
    if (w >= v[i].first)
        return dp[w][i] = max(f(w, i + 1), v[i].second + f(w - v[i].first, i + 1));
    else
        return dp[w][i] = f(w, i + 1);
}
void inforkc()
{
    memset(dp, -1, sizeof(dp));
    ll w;
    cin >> n >> w;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    cout << f(w);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    int t_e_s_t = 1;
    // cin>>t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}