#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int n, x, y;
    cin >> n >> x >> y;
    int s = ((n) * (n + 1)) / 2;
    if ((x + y) > s || (s % (x + y) != 0))
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << "POSSIBLE" << endl;
    int k = s / (x + y);
    k *= x;
    int i = 0, p = 0;
    while (p <= k)
    {
        i++;
        p += i;
    }
    int d = p - k;
    cout << i - 1 << endl;
    for (int j = 1; j <= i; j++)
    {
        if (j != d)
            cout << j << " ";
    }
    cout << endl;
}

signed main()
{
    int t_e_s_t;
    cin >> t_e_s_t;
    int i = 1;
    while (t_e_s_t--)
    {
        cout << "Case #" << i << ": ";
        inforkc();
        i++;
    }
    return 0;
}