#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int x, y;
    cin >> x >> y;
    if (y >= x)
    {
        if (y - x <= 2)
        {
            cout << "Yes";
        }
        else
            cout << "No";
    }
    else
    {
        if (x - y <= 3)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}