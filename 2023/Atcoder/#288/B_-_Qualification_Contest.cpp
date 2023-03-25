#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.begin() + k);
    for (int i = 0; i < k; i++)
        cout << v[i] << endl;
    return 0;
}