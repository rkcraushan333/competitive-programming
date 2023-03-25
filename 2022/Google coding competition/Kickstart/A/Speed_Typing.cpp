#include <bits/stdc++.h>
using namespace std;

void inforkc()
{
    string s, t;
    cin >> s >> t;
    if (s.size() >= t.size() && s != t)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int j = 0, count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[j] == t[j])
        {
            j++;
        }
        else
        {
            t.erase(j, 1);
            count++;
        }
    }
    if (t.size() < s.size())
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    else
    {
        string k = t.substr(0, s.size());
        cout << k << endl;
        if (k == s)
            cout << count + (t.size() - s.size()) << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
}
int main()
{
    int test;
    cin >> test;
    int i = 1;
    while (test--)
    {
        cout << "Case #" << i++ << ": ";
        inforkc();
    }
    return 0;
}