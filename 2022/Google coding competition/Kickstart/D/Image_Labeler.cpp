#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
const int mod = 1e9 + 7;

// by inforkc
void inforkc()
{
    int n, m;
    cin >> n >> m;
    double res = 0.0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        res += v[i];
    }
    if (n == m)
        cout << res << endl;
    else
    {
        sort(v.begin(), v.end());
        int a = n - m + 1;
        int k = 0;
        for (int i = 0; i < a; i++)
            k += v[i];
        res -= k;
        double d;
        if (a % 2 == 0)
            d = (v[(a / 2) - 1] + v[a / 2]) / 2.0;
        else
            d = (v[(a / 2)]);
        res += d;
        cout << fixed << setprecision(10);
        cout << res << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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