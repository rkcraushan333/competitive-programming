#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c = 0;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            if (A[i] % 2 != 0)
            {
                c += 1;
            }
        }
        if (c < 2)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << c / 2 << endl;
        }
    }
    return 0;
}