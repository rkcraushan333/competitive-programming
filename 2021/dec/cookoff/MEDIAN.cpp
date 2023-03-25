#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        sort(s, s + n);
        int m1 = (s[0] + s[n - 1]) / 2, m2 = s[n / 2];
        cout << abs(m1 - m2) << endl;
    }
    return 0;
}