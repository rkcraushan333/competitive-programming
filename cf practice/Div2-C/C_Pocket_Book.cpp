#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

// by inforkc
signed main()
{
    int n, m;
    cin >> n >> m;
    char c[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
    }
    int ans = 1;
    for (int i = 0; i < m; i++)
    {
        set<int> s;
        for (int j = 0; j < n; j++)
            s.insert(c[j][i]);
        int k = s.size();
        ans = ((ans % MOD) * (k % MOD)) % MOD;
    }
    cout << ans << endl;
    return 0;
}