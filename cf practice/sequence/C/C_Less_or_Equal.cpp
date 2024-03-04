#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    if (k == 0)
    {
        cout << (v[0] > 1 ? 1 : -1) << endl;
        return 0;
    }
    if (k == n)
    {
        cout << v[n - 1] << endl;
        return 0;
    }
    if (v[k] == v[k - 1])
    {
        cout << -1 << endl;
        return 0;
    }
    cout << v[k - 1] << endl;
    return 0;
}