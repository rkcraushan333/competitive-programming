#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int n;
    cin >> n;
    vector<vector<int>> v1(2);
    vector<vector<int>> v2(2);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v1[0].push_back(a);
        v1[1].push_back(b);
    }
    v2 = v1;
    sort(v1[0].begin(), v1[0].end());
    sort(v2[1].begin(), v2[1].end());
    int res = 0, k;
    for (int i = 0; i < n; i++)
    {
        if (v1[0][i] < v2[1][0])
            res = max(res, i + 1);
        else
        {
            k = lower_bound(v2[1].begin(), v2[1].end(), v1[0][i]) - v2[1].begin();
            if (v1[0][i] == v2[1][k])
            {
                res = max(res, i - k);
            }
            else
            {

                res = max(res, i + 1 - k);
            }
        }
    }
    cout << res;
}

signed main()
{
    // int t_e_s_t;
    // cin >> t_e_s_t;
    // while (t_e_s_t--)
    // {
    inforkc();
    // }
    return 0;
}