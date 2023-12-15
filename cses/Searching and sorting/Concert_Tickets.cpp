#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc

void inforkc()
{
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        s.insert(k);
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        auto a = s.upper_bound(k);
        if (a == s.begin())
            cout << -1 << endl;
        else if (s.size() > 0)
        {
            a--;
            cout << *a << endl;
            s.erase(a);
        }
        else
            cout << -1 << endl;
    }
}

signed main()
{
    inforkc();
    return 0;
}