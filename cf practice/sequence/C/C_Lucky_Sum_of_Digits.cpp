#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{
    int n;
    cin >> n;
    int k = n / 7, r = n % 7;
    while (r % 4 != 0 && k > 0)
    {
        r += 7;
        k--;
    }
    if (k == 0 && r % 4 != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    while (r > 1)
    {
        cout << 4;
        r -= 4;
    }
    while (k > 0)
    {
        cout << 7;
        k--;
    }
    return 0;
}