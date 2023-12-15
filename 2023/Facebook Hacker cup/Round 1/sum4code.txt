#include <iostream>
#include <bits/stdc++.h>
#define ll int
#define MOD 1000000007
#define ull unsigned long long
#define mxx 1e18 - 1
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x;
    cin >> x;
    map<ll, ll> mp;
    vector<ll> q;
    for (ll i = 0; i < x; i++)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second % 2 == 1)
        {
            q.push_back(it->first);
        }
    }
    vector<ll> v(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            v[i + 1] = 1;
        }
    }
    for (ll i = 0; i < q.size(); i++)
    {
        ll val = q[i];
        ll cnt = 1;
        while ((val * cnt) <= n)
        {
            v[val * cnt] ^= 1;
            cnt++;
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (v[i] == 1)
        {
            ans++;
            ll val = i;
            ll cnt = 1;
            while ((val * cnt) <= n)
            {
                v[val * cnt] ^= 1;
                cnt++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout.tie(NULL);
    ll tt;
    cin >> tt;
    ll cnt = 1;
    while (tt--)
    {
        cout << "Case #" << cnt << ": ";
        solve();
        cnt++;
    }
    return 0;
}