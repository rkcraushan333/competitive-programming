#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int n, b;
    cin >> n >> b;
    vector<int> v(n + 1);
    map<int, int> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        int k = v[i];
        if (m.count(b - k))
        {
            cout << i << " " << m[b - k];
            return;
        }
        m[k] = i;
    }
    cout << "IMPOSSIBLE";
}

signed main()
{
    //     int t_e_s_t;
    //     cin>>t_e_s_t;
    //     while(t_e_s_t--)
    //     {
    inforkc();
    //     }
    return 0;
}