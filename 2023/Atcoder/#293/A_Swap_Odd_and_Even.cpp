#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i += 2)
    {
        swap(s[i], s[i + 1]);
    }
    cout << s;
    return 0;
}