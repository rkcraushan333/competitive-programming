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
#define yy cout << "Yes" << ln
#define nn cout << "No" << ln
#define pi 3.14159265358979323846
#define rsz resize
#define inc(v) sort(v.begin(), v.end())
#define dec(v) sort(v.rbegin(), v.rend())
const int mod = 1e9 + 7;
#define dbg cout << "debug" << ln;

// for inverse modulo (k^mod-2)%mod
// by inforkc
int f(string &s, int i, vector<vector<vector<int>>> &dp, int mask = 0, int done = 0)
{
    if (i == -1)
        return 0;
    int &rkc = dp[i][mask][done];
    if (rkc != INT_MIN)
        return rkc;
    int ans = -1e9;
    int c = s[i] - 'A';
    int t = pow(10, c);
    if (mask > c)
        t *= -1;
    if (done)
    {
        ans = max(ans, t + f(s, i - 1, dp, max(mask, c), done));
    }
    else
    {
        ans = max(ans, t + f(s, i - 1, dp, max(mask, c), done));
        forn(k, 0, 5)
        {
            int a = pow(10, k);
            ans = max(ans, a + f(s, i - 1, dp, max(mask, k), 1));
        }
    }
    return rkc = ans;
}
void inforkc()
{
    string s;
    cin >> s;
    vector<vector<vector<int>>> dp(s.size(), (vector<vector<int>>(5, vector<int>(2))));
    forn(i, 0, s.size())
    {
        forn(j, 0, 5)
        {
            forn(k, 0, 2)
            {
                dp[i][j][k] = INT_MIN;
            }
        }
    }
    cout << f(s, s.size() - 1, dp) << ln;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // sieve();
    // factorial();
    int t_e_s_t = 1;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}