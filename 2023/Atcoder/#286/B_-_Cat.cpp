#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "";
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (s[i] == 'n' && s[i + 1] == 'a')
        {
            t += "nya";
            i++;
        }
        else
        {
            t.push_back(s[i]);
        }
    }
    if (i == n - 1)
    {
        t.push_back(s[n - 1]);
    }
    cout << t << endl;
    return 0;
}