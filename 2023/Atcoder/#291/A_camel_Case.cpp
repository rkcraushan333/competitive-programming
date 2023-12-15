#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < 95)
        {
            cout << i + 1;
        }
    }
    return 0;
}