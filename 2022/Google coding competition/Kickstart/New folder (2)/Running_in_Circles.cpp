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
    int l, n;
    cin >> l >> n;
    int res = 0, p = 0;
    while (n--)
    {
        int a;
        char c;
        cin >> a >> c;
        if (c == 'A')
            a -= (2 * a);

        p += a;
        int t = abs(p) / l;
        res += t;
        if (p > 0)
        {
            p -= (t * l);
        }
        else
        {
            p += t * l;
        }
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