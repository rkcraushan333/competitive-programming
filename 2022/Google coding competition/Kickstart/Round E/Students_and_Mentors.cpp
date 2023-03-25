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
pair<int, int> search(vector<pair<int, int>> &v, int a)
{
    int s = -1, e = v.size(), t = 0;
    while (e - s > 1)
    {
        int m = (s + e) / 2;
        if (v[m].first <= a)
        {
            s = m;
            t = v[m].second;
        }
        else
            e = m;
    }
    return {s, t};
}
void inforkc()
{
    int n;
    cin >> n;
    vec v(n);
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        vp.push_back({v[i], i});
    }
    sort(vp.begin(), vp.end());
    for (int i = 0; i < n; i++)
    {
        int a = 2 * v[i];
        pair<int, int> k = search(vp, a);
        if (k.first == -1)
        {
            cout << -1 << " ";
            continue;
        }

        if (k.second == i)
        {
            if (k.first != 0)
                cout << vp[k.first - 1].first << " ";
            else
                cout << -1 << " ";
            continue;
        }
        cout << vp[k.first].first << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t_e_s_t;
    cin >> t_e_s_t;
    int i = 1;
    while (i <= t_e_s_t)
    {
        cout << "Case #" << i++ << ": ";
        inforkc();
        cout << endl;
    }
    return 0;
}