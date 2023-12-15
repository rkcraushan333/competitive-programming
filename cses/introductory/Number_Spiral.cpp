#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int a, b;
    cin >> a >> b;
    int m = max(a, b);
    if (m == a)
    {
        if (a % 2 == 0)
        {
            cout << (a * a) - (b - 1) << endl;
        }
        else
        {
            cout << (a - 1) * (a - 1) + b << endl;
        }
    }
    else
    {
        if (b & 1)
        {
            cout << (b * b) - (a - 1) << endl;
        }
        else
        {
            cout << (b - 1) * (b - 1) + a << endl;
        }
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