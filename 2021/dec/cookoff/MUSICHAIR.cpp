#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        a--;
        int k = 0;
        for (int i = 1; i <= sqrt(a); i++)
        {
            if (a % i == 0)
            {
                k++;
                if (i != sqrt(a))
                {
                    k++;
                }
            }
        }
        cout << k << endl;
    }
    return 0;
}