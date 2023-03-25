#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cout << ((i + 1) * (i + 1)) - (i * i) << " ";
        }
        cout << endl;
    }
    return 0;
}