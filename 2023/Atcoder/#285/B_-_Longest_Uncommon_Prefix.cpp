#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; i++)
    {
        int res = 0;
        for (int j = 0; j + i < s.size(); j++)
        {
            if (s[j] == s[j + i])
                break;
            else
                res++;
        }
        cout << res << endl;
    }
    return 0;
}