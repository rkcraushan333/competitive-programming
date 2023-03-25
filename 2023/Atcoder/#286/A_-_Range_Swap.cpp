#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n;
    cin >> n;
    int p, q, r, s;
    cin >> p >> q >> r >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k = q - p + 1;
    while (k--)
    {
        swap(v[p - 1], v[r - 1]);
        p++;
        r++;
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    return 0;
}