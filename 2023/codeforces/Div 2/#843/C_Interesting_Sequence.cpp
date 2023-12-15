#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc

// code to find & for a range
int f(int m, int n)
{
    int i = 0;
    while (m != n)
    {
        i++;
        m >>= 1;
        n >>= 1;
    }
    return m << i;
}
void inforkc()
{
    int n, x;
    cin >> n >> x;
    int s = n, e = 5e18, ans = -1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        int val = f(n, m);
        if (val > x)
            s = m + 1;
        else if (val <= x)
        {
            if (val == x)
                ans = m;
            e = m - 1;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    int t_e_s_t;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}