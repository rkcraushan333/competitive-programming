#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (auto &i : s)
    {
        if (i == '0')
            i = 'o';
        if (i == '1')
            i = 'l';
    }
    for (auto &i : t)
    {
        if (i == '0')
            i = 'o';
        if (i == '1')
            i = 'l';
    }
    if (s == t)
    {
        cout << "Yes";
    }
    else
        cout << "No";
    return 0;
}