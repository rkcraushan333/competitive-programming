#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define v64 vector<int>
#define vp64 vector<pair<int, int>>
#define forn(i, a, b) for (int i = a; i < b; i++)
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define pqmax priority_queue<int>
#define ln "\n"
vector<int> prime;
void sieve()
{
    prime.resize(1e7 + 10);
    for (int i = 0; i < prime.size(); i++)
    {
        prime[i] = 1;
    }
    for (int i = 2; i <= 1e7; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = 2 * i; j <= 1e7; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
vector<int> check;
void calculate()
{
    check.resize(1e7 + 10);
    check[2] = 1;
    for (int i = 3; i <= 1e7; i++)
    {
        if (prime[i] == 1)
        {
            if (prime[i + 2] == 1)
            {
                check[i] = 1;
            }
        }
    }
    for (int i = 3; i <= 1e7; i++)
    {
        check[i] += check[i - 1];
    }
}
// for inverse modulo (k^mod-2)%mod
// by inforkc => don't use hashing in codeforces instead use set and map
void inforkc()
{
    int n;
    cin >> n;
    if (n < 5)
    {
        cout << 0 << ln;
        return;
    }

    // for (int i = 0; i < 12; i++)
    // {
    //     cout << check[i] << " ";
    // }
    cout << check[n - 2] << ln;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("inputv.txt", "r", stdin);
    freopen("outputv.txt", "w", stdout);
    sieve();
    calculate();
    // factorial();
    int t_e_s_t;
    cin >> t_e_s_t;
    int i = 1;
    while (i <= t_e_s_t)
    {
        cout << "Case #" << i++ << ": ";
        inforkc();
    }
    return 0;
}