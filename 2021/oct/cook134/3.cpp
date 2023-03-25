#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        scanf("%d", &n);

        if (n < 3)
        {
            if (n == 0)
            {
                printf("%d", sum);
            }
            else
            {
                printf("%d", sum + 1);
            }
        }
        else
        {
            sum = 1 + ((n - 1) * (n - 2));
            printf("%d\n", sum);
        }
    }
    return 0;
}