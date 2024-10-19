#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define mxx 1e18 - 1
typedef long double ld;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
    ll totalTestCase;
    cin >> totalTestCase;
    for (ll tc = 1; tc <= totalTestCase; tc++)
    {
        long double a = 1e18;
        long double b = -1e18;
        long double ans = -1;
        ll n;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            long double right = ld(i + 1) / x;
            long double left = ld(i + 1) / y;
            b = max(left, b);
            a = min(right, a);
        }
        if (b <= a)
        {
            ans = b;
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}