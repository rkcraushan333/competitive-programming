#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long // by inforkc
void inforkc()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (a % 5 == 0 || a > b)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> v = {1, 2, 4, 3};
    map<int, int> m;
    for (int i = 0; i < 4; i++)
    {
        m[v[i]] = i;
    }
    int c = b - a;
    int res = (c / 10) * 4;
    c %= 10;
    int p = m[a % 5];
    for (int i = p;; i = (i + 1) % 4)
    {
        if (c == 0)
        {
            cout << res << endl;
            return;
        }
        if (c < 0)
            break;
        c -= v[i];
        res++;
    }
    cout << -1 << endl;
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