#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        if (a % 3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        int aa = min(a, b);
        int bb = max(a, b);
        if (bb > (2 * aa))
        {
            cout << "NO" << endl;
            return;
        }
        int d = bb - aa;
        aa -= d;
        bb -= (2 * d);
        if (aa % 3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

signed main()
{
    int t_e_s_t;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}