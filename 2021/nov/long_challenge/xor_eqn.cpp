#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        int A[n], sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            sum = sum ^ A[i];
        }
        if (sum % 3 == 0)
        {
            while (sum % 3 == 0)
            {
                sum = sum / 3;
            }
            cout << sum << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}