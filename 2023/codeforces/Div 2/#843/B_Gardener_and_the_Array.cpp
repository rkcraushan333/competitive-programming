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
    vector<vector<int>> v;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<int> t(k);
        for (int j = 0; j < k; j++)
        {
            cin >> t[j];
            m[t[j]]++;
        }
        v.push_back(t);
    }
    for (auto t : v)
    {
        bool k = 1;
        for (auto i : t)
        {
            if (m[i] < 2)
            {
                k = 0;
                break;
            }
        }
        if (k)
        {
            cout << "YES" << endl;
            return;
        }
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