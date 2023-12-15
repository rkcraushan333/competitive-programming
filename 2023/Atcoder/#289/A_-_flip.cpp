#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    string s;
    cin >> s;
    for (auto &i : s)
    {
        if (i == '0')
            i = '1';
        else
            i = '0';
    }
    cout << s;
    return 0;
}