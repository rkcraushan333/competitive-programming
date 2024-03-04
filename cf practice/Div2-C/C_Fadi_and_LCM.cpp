#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    for (int i = sqrt(n); i >= 1; i--)
    {
        if ((n % i == 0) && (i * i != n))
        {
            int a = i, b = n / i;
            if (__gcd(a, b) == 1)
            {
                cout << i << " " << n / i << endl;
                return 0;
            }
        }
    }
    return 0;
}