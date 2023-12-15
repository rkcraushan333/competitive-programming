#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = n - 1; i >= 0; i--)
        cout << v[i] << endl;
    return 0;
}