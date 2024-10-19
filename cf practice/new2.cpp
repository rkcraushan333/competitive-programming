#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int f(vector<int> &v)
{
    int n = v.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        unordered_set<string> st;
        string s = to_string(v[i]);
        st.insert(s);
        for (int k = 1; k < s.size(); k++)
        {
            int cc = s.size();
            int j = k;
            string t = "";
            while (cc--)
            {
                t += s[j];
                j += 1;
                j %= s.size();
            }
            st.insert(t);
            cout << t << " ";
        }

        bool ok = 0;
        for (auto x : st)
        {
            if (mp.count(x))
            {
                mp[x]++;
                ok = 1;
                break;
            }
        }
        if (ok == 0)
        {
            mp[s]++;
        }
    }
    int ans = 0;
    for (auto i : mp)
    {
        int x = i.second;
        if (x > 1)
        {
            ans += (x * (x - 1)) / 2;
        }
    }
    return ans;
}
signed main()
{
    vector<int> v = {13, 5604, 31, 2, 13, 4560, 546, 654, 456};
    cout << f(v);
    return 0;
}