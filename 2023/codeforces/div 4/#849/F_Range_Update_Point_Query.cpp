#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
int sum(int n)
{
    int ans = 0;
    while (n)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
void inforkc()
{
    int n, q;
    cin >> n, q;
    vector<int> v(n);
    multiset<int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m.insert(i);
        m.insert(i);
        m.insert(i);
    }
    m.insert(INT_MAX);
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int l, r;
            cin >> l, r;
            l--;
            r--;
            auto t = m.lower_bound(l);
            vector<int> vis;
            while (*t <= r)
            {
                auto temp = t;
                t = m.upper_bound(*t);
                m.erase(*temp);
            }
        }
        else
        {
            int x;
            cin >> x;
            x--;
            int time = 3 - m.count(x);
            int s = v[x];
            for (int i = 0; i < time; i++)
            {
                s = sum(s);
            }
            cout << s << endl;
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