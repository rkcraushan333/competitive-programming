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
    int n;
    cin >> n;
    if (n < 4)
        cout << 1 << endl;
    else
    {
        int cnt = 1;
        int t = 0;
        for (int i = 4; i <= n;)
        {
            if (t % 2 == 0)
            {
                i += 2;
                t++;
            }
            else
            {
                i += 3;
                t++;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
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