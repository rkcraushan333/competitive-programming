#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
string f(string s, char c)
{
    int n = s.size();
    string t;
    bool ok = 0;
    for (int i = 0; i < n; i++)
    {
        if (ok == 0)
        {
            if (c <= 'Z' && c >= 'A')
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    if (s[i] < c)
                    {
                        ok = 1;
                        t += c;
                    }
                }
                else
                {
                    t += c;
                    ok = 1;
                }
            }
            else if (c >= 'a' && c <= 'z')
            {
                if (s[i] >= 'a' && s[i] <= 'z')
                {
                    if (s[i] < c)
                    {
                        t += c;
                        ok = 1;
                    }
                }
            }
        }

        t += s[i];
    }
    if (ok == 0)
    {
        t += c;
    }
    return t;
}
signed main()
{
    string s;
    char c;
    cin >> s >> c;
    cout << f(s, c);
    return 0;
}