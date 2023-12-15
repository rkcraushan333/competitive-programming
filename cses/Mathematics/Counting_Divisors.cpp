#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{
    int divisor[1000001];
    for (int i = 1; i < 1000001; i++)
        divisor[i] = 1;
    for (int i = 2; i < 1000001; i++)
    {
        for (int j = i; j < 1000001; j += i)
        {
            divisor[j]++;
        }
    }
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        cout << divisor[k] << endl;
    }
    return 0;
}