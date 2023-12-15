#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int res = 0, prev = v[0];
    for (int i = 1; i < n; i++)
    {
        int k = max(v[i], prev);
        prev = k;
        res += (k - v[i]);
    }
    cout << res;
}

signed main()
{
    inforkc();
    return 0;
}