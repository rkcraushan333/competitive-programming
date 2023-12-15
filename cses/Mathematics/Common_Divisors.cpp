#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n;
    cin >> n;
    unordered_map<int, int> m;
    while (n--)
    {
        int k;
        cin >> k;
        m[k]++;
    }
    int ans = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        int c = 0;
        for (int j = i; j <= 1000000; j += i)
        {
            if (m.find(j) != m.end())
            {
                if (c)
                {
                    ans = i;
                    break;
                }
                if (m[j] > 1)
                {
                    ans = i;
                    break;
                }
                c = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}