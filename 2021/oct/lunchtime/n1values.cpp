#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p = 2;
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            if (i == 0 || i == 1)
            {
                cout << "1 ";
            }
            else
            {
                cout << p << " ";
                p = p * 2;
            }
        }
        cout << "\n";
    }
    return 0;
}