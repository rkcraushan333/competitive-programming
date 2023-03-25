#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int n;
    string s;
    cin >> n >> s;
    vector<char> v;
    unordered_set<char> u;
    for (int i = 0; i < n; i++)
    {
        v.push_back(s[i]);
        u.insert(s[i]);
    }
    bool check = false;
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (u.find(i) != u.end())
        {
            check = true;
            break;
        }
    }
    if (!check)
    {
        v.push_back('a');
    }
    check = false;
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (u.find(i) != u.end())
        {
            check = true;
            break;
        }
    }
    if (!check)
    {
        v.push_back('A');
    }
    check = false;
    char arr[4] = {'#', '@', '*', '&'};
    for (int i = 0; i < 4; i++)
    {
        if (u.find(arr[i]) != u.end())
        {
            check = true;
        }
    }
    if (!check)
        v.push_back('#');
    check = false;
    for (int i = '0'; i <= '9'; i++)
    {
        if (u.find(i) != u.end())
        {
            check = true;
            break;
        }
    }
    if (!check)
    {
        v.push_back('1');
    }
    if (v.size() < 7)
    {
        int k = 7 - v.size();
        while (k--)
        {
            v.push_back('1');
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << endl;
}

signed main()
{
    int t_e_s_t;
    cin >> t_e_s_t;
    int i = 1;
    while (t_e_s_t--)
    {
        cout << "Case #" << i << ": ";
        inforkc();
        i++;
    }
    return 0;
}