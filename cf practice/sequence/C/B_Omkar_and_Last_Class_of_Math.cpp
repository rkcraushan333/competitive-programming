#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int lcm(int a, int b)
{
    return ((a * b) / __gcd(a, b));
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
            cout << n / 2 << " " << n / 2 << endl;
        else
        {
            int res = INT_MAX;
            int a, b;
            vector<int> v;
            for (int i = 1; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    if (i * i == n)
                        v.push_back(i);
                    else
                    {
                        v.push_back(i);
                        v.push_back(n / i);
                    }
                }
            }
            for (auto i : v)
            {
                if (i != n)
                {
                    if (n % i == 0)
                    {
                        int k = lcm(i, n - i);
                        if (res > k)
                        {
                            res = k;
                            a = i;
                            b = n - i;
                        }
                    }
                }
            }
            cout << a << " " << b << endl;
        }
    }
    return 0;
}