#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{
    int n, m;
    cin >> n >> m;
    int k = n - m + 1;
    int q = n / m, r = n % m;
    int mx = ((k - 1) * (k)) / 2;
    int mn = 0;
    for (int i = 0; i < r; i++)
        mn += (q * (q + 1)) / 2;

    for (int i = 0; i < m - r; i++)
        mn += (q * (q - 1)) / 2;

    cout << mn << " " << mx << endl;
    return 0;
}