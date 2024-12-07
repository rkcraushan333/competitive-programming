#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
#define ln endl
const int mod = 1e9 + 7;
// by inforkc
void inforkc()
{
    int n;
    cin >> n;
    vector<pair<double, double>> v;
    double mn = INT64_MIN, mx = INT64_MAX;
    for (int i = 1; i < n + 1; i++)
    {
        double a, b, c, d;
        cin >> a >> b;
        v.push_back({a, b});
        if (a != 0)
            d = i / a;
        else
            d = INT64_MAX;
        if (b != 0)
            c = i / b;
        else
            c = i / b;
        mn = max(c, mn);
        mx = min(d, mx);
    }
    if (mn > mx)
    {
        cout << -1 << ln;
    }
    else
    {
        cout << fixed << setprecision(12);
        cout << mn << ln;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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