#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p, sum = 0, n = 0, k = 0;
        cin >> p;
        int div[p];
        for (int i = 0; i < p; i++)
        {
            cin >> div[i];
            if (div[i] % 3 != 0)
            {
                n++;
                if ((div[i] + 1) % 3 == 0)
                {
                    k++;
                }
            }
            sum = sum + div[i];
        }
        int a = abs(n - k - k);

        if (sum % 3 == 0)
        {
            if (k == n / 2)
            {
                cout << k << endl;
            }
            else
            {
                cout <<((n-a)/2) + (a-1)<<endl;
            }
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}