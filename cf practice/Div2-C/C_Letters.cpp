#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int s = 0, e = n - 1;
        while (s <= e)
        {
            int m = (s + e) / 2;
            if (a[m] == k)
            {
                s = m;
                break;
            }
            else if (a[m] < k)
                s = m + 1;
            else
                e = m - 1;
        }
        if (s == 0)
            cout << s + 1 << " " << k << endl;
        else
            cout << s + 1 << " " << k - a[s - 1] << endl;
    }

    return 0;
}