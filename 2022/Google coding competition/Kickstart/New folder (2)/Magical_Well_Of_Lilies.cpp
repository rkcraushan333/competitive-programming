#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
const int mod = 1e9 + 7;
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return (t * t);
    else
        return (a * t * t);
}
// by inforkc
void inforkc()
{
    int l;
    cin >> l;
    // if (l < 14)
    // {
    //     cout << l << endl;
    //     return;
    // }
    int res = l, i = 2;

    while (i < l)
    {
        int q = l / i;
        int r = l % i;
        if (q == 1)
        {
            res = min(res, i + r);
        }
        else
        {
            res = min(res, i + 6 + (q - 2) * 2 + r);
        }
        // cout << res << " " << i << " " << q << endl;
        i++;
    }
    cout << res << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t_e_s_t;
    cin >> t_e_s_t;
    int i = 1;
    while (i <= t_e_s_t)
    {
        cout << "Case #" << i++ << ": ";
        inforkc();
    }
    return 0;
}