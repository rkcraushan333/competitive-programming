#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int car[n];
        for (int i = 0; i < n; i++)
        {
            cin >> car[i];
        }
        int k = 1;
        int p = car[0];
        for (int i = 0; i < n - 1; i++)
        {
            if (p > car[i + 1])
            {
                k += 1;
                p = car[i + 1];
            }
        }
        cout << k << endl;
    }
    return 0;
}