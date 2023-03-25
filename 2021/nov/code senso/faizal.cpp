#include <bits/stdc++.h>
using namespace std;
#define int long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ((n - n / 2) * 3) - n / 2 << endl;
    }
    return 0;
}