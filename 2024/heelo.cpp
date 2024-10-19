#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 1e6 + 1

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), freqA(N, 0), freqB(N, 0);

    for (ll i = 0; i < n; i++)
        cin >> a[i], freqA[a[i]]++;

    for (ll j = 0; j < n; j++)
        cin >> b[j], freqB[b[j]]++;

    vector<ll> dp(N, 0);
    ll ans = 0;

    for (ll i = N; i >= 2; --i)
    {
        ll cntA = 0, cntB = 0, sub = 0;

        for (ll j = i; j <= N; j += i)
        {
            cntA += freqA[j];
            cntB += freqB[j];
            sub += dp[j];
        }

        ll pairsWithGcdI = cntA * cntB - sub;
        ans += pairsWithGcdI;
        dp[i] = pairsWithGcdI;
    }

    cout << ans << "\n";
}
