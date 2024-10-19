#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc

int f(vector<int> &v)
{
    int n = v.size();
    map<int, int> mp;
    for (auto i : v)
    {
        mp[i]++;
    }
    vector<pair<int, int>> vp;
    int ans = 0;
    for (auto i : mp)
    {
        vp.push_back({i.first, i.second});
        if (i.second > 2)
        {
            int cnt = i.second;
            ans += (cnt * (cnt - 1) * (cnt - 2)) / 6;
        }
    }
    for (int i = 0; i < vp.size(); i++)
    {
        for (int j = i + 1; j < vp.size(); j++)
        {
            int val = vp[i].first + vp[j].first;
            if (val % 2 == 0)
            {
                val /= 2;
                if (mp.count(val))
                {
                    ans += (mp[val] * vp[i].second * vp[j].second);
                }
            }
        }
    }
    return ans;
}
signed main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return 0;
}