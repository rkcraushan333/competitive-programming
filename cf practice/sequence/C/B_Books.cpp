#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // USING SLIDING WINDOW
    int i = 0, j = 0, s = 0, res = 0;
    while (j < n)
    {
        s += v[j];
        if (s <= t)
            res = max(res, j - i + 1);
        while (s > t)
        {
            s -= v[i];
            i++;
        }
        j++;
    }
    cout << res << endl;
    return 0;
}