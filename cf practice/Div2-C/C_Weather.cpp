#include <bits/stdc++.h>
using namespace std;
#define int long long
#define v64 vector<int>
#define vp64 vector<pair<int, int>>
#define p64 pair<int, int>
#define forn(i, a, b) for (int i = a; i < b; i++)

// by inforkc
int lelo;
v64 sexy;
int dp[100001][2];
int baby_please_do_it(int i = 0, bool t = 0)
{
    if (i == lelo)
        return 0;
    if (dp[i][t] != -1)
        return dp[i][t];
    int res = INT64_MAX;
    if (i == 0)
    {
        if (sexy[i] >= 0)
        {
            res = min(res, 1 + baby_please_do_it(i + 1, 0));
        }
        else
        {
            res = min(res, baby_please_do_it(i + 1, 0));
        }
    }
    else if (i == lelo - 1)
    {
        if (sexy[i] <= 0)
        {
            res = min(res, 1 + baby_please_do_it(i + 1, 1));
        }
        else
            res = min(res, baby_please_do_it(i + 1, 1));
    }
    else
    {
        if (t)
        {
            if (sexy[i] <= 0)
            {
                res = min(res, 1 + baby_please_do_it(i + 1, 1));
            }
            else
                res = min(res, baby_please_do_it(i + 1, 1));
        }
        else
        {
            if (sexy[i] < 0)
            {
                res = min(res, baby_please_do_it(i + 1, 0));
            }
            else if (sexy[i] > 0)
            {
                res = min(res, 1 + baby_please_do_it(i + 1, 0));
                res = min(res, baby_please_do_it(i + 1, 1));
            }
            else
            {
                res = min(res, 1 + baby_please_do_it(i + 1, 0));
            }
        }
    }
    return dp[i][t] = res;
}
void inforkc()
{
    memset(dp, -1, sizeof(dp));
    cin >> lelo;
    sexy.resize(lelo);
    forn(i, 0, lelo)
    {
        cin >> sexy[i];
    }
    cout << baby_please_do_it();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t_e_s_t = 1;
    // cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}