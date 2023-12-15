#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{
    int n;
    cin >> n;
    vector<int> v(5 * n);
    double res = 0;
    for (int i = 0; i < 5 * n; i++)
    {
        cin >> v[i];
        res += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        res -= v[i];
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n; i++)
    {
        res -= v[i];
    }
    cout << fixed;
    cout << setprecision(20);
    double t = 3 * n;
    res = res / t;
    cout << res;
    return 0;
}