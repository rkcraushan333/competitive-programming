#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (a & 1)
            continue;
        cout << a << " ";
    }
    return 0;
}