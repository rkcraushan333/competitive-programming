#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans ^= i;
    }
    for (int i = 1; i < n; i++)
    {
        int in;
        cin >> in;
        ans ^= in;
    }
    cout << ans << endl;
}

signed main()
{
    inforkc();
    return 0;
}