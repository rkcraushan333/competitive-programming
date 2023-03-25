#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int c;
            cin >> c;
            if (c == 0)
                cout << ".";
            else
            {
                c--;
                char t = 'A' + c;
                cout << t;
            }
        }
        cout << endl;
    }
    return 0;
}