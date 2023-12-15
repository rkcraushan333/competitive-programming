#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
        {
            if (a < k)
            {
                a++;
            }
            else
            {
                s[i] = 'x';
            }
        }
    }
    cout << s;
    return 0;
}