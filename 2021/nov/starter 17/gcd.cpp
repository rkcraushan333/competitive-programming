#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, count = 0;
        cin >> k;
        int gcd[k];
        for (int i = 0; i < k; i++)
        {
            cin >> gcd[i];
        }
        for (int i = 0; i < k - 1; i++)
        {
            if (gcd[i] % gcd[i + 1])
                count = 1;
        }
        if (count)
        {
            cout << "-1\n";
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                cout << gcd[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}