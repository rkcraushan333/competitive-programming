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
    vec v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> msk(32, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (v[i] & (1 << j))
                msk[j]++;
        }
    }
    int x = 0;
    for (auto i : msk)
    {
        x += (i % 2);
    }
    if (x == 0)
    {
        cout << "YES" << endl;
        return;
    }
    if ((n - 1) % 2 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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