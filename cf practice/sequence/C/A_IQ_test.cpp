#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    int one = 0, zero = 0, x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] &= 1;
        if (v[i])
        {
            one++;
            x = i + 1;
        }
        else
        {
            zero++;
            y = i + 1;
        }
    }
    if (one == 1)
        cout << x << endl;
    else
        cout << y << endl;
    return 0;
}