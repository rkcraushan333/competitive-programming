#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, v;
        cin >> n >> v;
        int min = 0, k = n - 1;
        for (int i = 1; k > 0; i++)
        {
            if (k >= v)
            {
                min += v * i;
                k = k - v;
            }
            else
            {
                min += k * i;
                k = k - k;
            }
        }
        cout << (n * (n - 1)) / 2 << " " << min << endl;
    }
    return 0;
}