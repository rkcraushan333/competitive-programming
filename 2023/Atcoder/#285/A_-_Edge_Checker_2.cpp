#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int a1, b1;
    cin >> a1 >> b1;
    if ((b1 == 2 * a1) || (b1 == (2 * a1) + 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}