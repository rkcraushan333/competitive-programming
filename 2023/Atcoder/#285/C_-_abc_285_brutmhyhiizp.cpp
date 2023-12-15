#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return (t * t);
    else
        return (a * t * t);
}
signed main()
{
    string s;
    cin >> s;
    int res = 0, j = 0;
    reverse(s.begin(), s.end());
    for (j = 0; j < s.size(); j++)
    {
        res += (fastpow(26, j) * (s[j] - 'A' + 1));
    }
    cout << res << endl;
    return 0;
}