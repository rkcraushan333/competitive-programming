#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
signed main()
{

    int n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if (n & 1)
        {
            n = (n * 3) + 1;
            cout << n << " ";
        }
        else
        {
            n /= 2;
            cout << n << " ";
        }
    }
    return 0;
}