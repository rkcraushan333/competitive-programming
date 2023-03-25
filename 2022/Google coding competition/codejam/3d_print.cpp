#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int v1[4], v2[4], v3[4], v4[4];
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> v1[i];
        v4[i] = v1[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> v2[i];
        v4[i] = min(v4[i], v2[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> v3[i];
        v4[i] = min(v4[i], v3[i]);
        sum += v4[i];
    }

    if (sum < 1000000)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int d = sum - 1000000;
    for (int i = 0; i < 4; i++)
    {
        if (v4[i] >= d)
        {
            v4[i] -= d;
            break;
        }
        else
        {
            d -= v4[i];
            v4[i] = 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << v4[i] << " ";
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
        cout << "Case "
             << "#" << i++ << ": ";
        inforkc();
    }
    return 0;
}