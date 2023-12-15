#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
void inforkc()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), compare);

    int res = 1, prev = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= prev)
        {
            prev = v[i].second;
            res++;
        }
    }
    cout << res;
}

signed main()
{
    // int t_e_s_t;
    // cin>>t_e_s_t;
    // while(t_e_s_t--)
    // {
    inforkc();
    // }
    return 0;
}