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
    int a = -1, b = -1, c = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '|')
        {
            if ((a != -1) & (b != -1))
            {
                cout << "in";
                return 0;
            }
            else if (a == -1)
            {
                a = i;
            }
            else
            {
                cout << "out";
                return 0;
            }
        }
        if (s[i] == '*')
        {
            if (a == -1)
            {
                cout << "out";
                return 0;
            }
            b = i;
        }
    }
    cout << "out";
    return 0;
}