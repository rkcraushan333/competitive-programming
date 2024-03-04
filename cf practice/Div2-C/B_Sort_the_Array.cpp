#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    v2 = v1;
    sort(v2.begin(), v2.end());
    int a = -1, b = -1;
    for (int i = 0; i < n; i++)
    {
        if (v1[i] != v2[i])
        {
            a = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (v1[i] != v2[i])
        {
            b = i;
            break;
        }
    }
    if (a == -1)
    {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
    }
    else
    {
        int i = a;
        while (a < b)
        {
            if (v1[a] < v1[a + 1])
            {
                cout << "no" << endl;
                return 0;
            }
            a++;
        }
        cout << "yes" << endl;
        cout << i + 1 << " " << b + 1 << endl;
    }
    return 0;
}