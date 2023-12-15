#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
int factorial(int n)
{
    if (n == 1)
        return 1;
    returnn *factorial(n - 1);
}
void printString()
{
}
signed main()
{
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    int res = 1;
    res = factorial(s.length());
    for (auto i : m)
    {
        if (i.second > 1)
        {
            res /= factorial(i.second);
        }
    }
    cout << res << endl;
    printString(s);
    return 0;
}