#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n;
    cin >> n;
    int k = (n + 1) / 2;
    int cnt = 0;
    while (n--)
    {
        string t;
        cin >> t;
        if (t == "For")
            cnt++;
    }
    if (cnt >= k)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}