#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n, m;
    cin >> n >> m;
    unordered_set<string> s;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        v.push_back(t.substr(3, 3));
    }
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        s.insert(t);
    }
    int cnt = 0;
    for (auto i : v)
    {
        if (s.find(i) != s.end())
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}