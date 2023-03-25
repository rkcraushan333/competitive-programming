#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }
    if (m[s[0]] == s.size())
    {
        cout << s << endl;
        return;
    }

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] <= s[i + 1])
        {
            cout << s[i] << s[i];
        }
        else
        {
            cout << s[i];
        }
    }
    int n = s.size();
    if (s[n - 1] <= s[n - 2])
    {
        cout << s[n - 1] << s[n - 1];
    }
    else
        cout << s[n - 1];
    cout << "\n";
}

signed main()
{
    int t_e_s_t;
    cin >> t_e_s_t;
    int i = 1;
    while (t_e_s_t--)
    {
        cout << "Case "
             << "#" << i++ << ": ";
        inforkc();
    }
    return 0;
}