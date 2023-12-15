#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    string s;
    cin >> s;
    int res = 1, count = 1;
    ;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        res = max(res, count);
    }
    cout << res;
}

signed main()
{
    inforkc();
    return 0;
}