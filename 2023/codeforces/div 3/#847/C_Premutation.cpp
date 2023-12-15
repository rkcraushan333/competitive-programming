#include <bits/stdc++.h>
using namespace std;

#define int long long
// by inforkc
void inforkc()
{
    int n;
    cin >> n;
    int v[n][n - 1];
    int a, b, ca = 0, cb = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            cin >> v[i][j];
        }
        if (i == 0)
        {
            a = v[i][0];
            ca++;
        }
        else
        {
            if (v[i][0] == a)
                ca++;
            else
            {
                b = v[i][0];
                cb++;
            }
        }
    }
    if (ca == 1)
    {
        swap(a, b);
    }
    cout << a << " ";
    for (int i = 0; i < n; i++)
    {
        if (a != v[i][0])
        {
            for (auto j : v[i])
            {
                cout << j << " ";
            }
            cout << endl;
            return;
        }
    }
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