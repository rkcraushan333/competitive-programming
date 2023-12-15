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
    bool check = true;
    int f;
    char a;
    if (s.size() & 1)
    {
        int count = 0;
        for (auto i : m)
        {
            if (i.second & 1)
            {
                f = i.second;
                a = i.first;
                count++;
            }
            if (count > 1)
            {
                check = 0;
                break;
            }
        }
    }
    else
    {
        for (auto i : m)
        {
            if (i.second & 1)
            {
                check = 0;
                break;
            }
        }
    }

    if (!check)
    {
        cout << "NO SOLUTION";
        return;
    }
    if (s.size() % 2 == 0)
    {
        vector<char> ch;
        for (auto i : m)
        {
            int k = i.second / 2;
            while (k--)
            {
                cout << i.first;
                ch.push_back(i.first);
            }
        }
        for (int i = ch.size() - 1; i >= 0; i--)
        {
            cout << ch[i];
        }
    }
    else
    {
        vector<char> ch;

        for (auto i : m)
        {
            int k = i.second;
            if (k % 2 == 0)
            {
                k /= 2;
                while (k--)
                {
                    cout << i.first;
                    ch.push_back(i.first);
                }
            }
        }
        while (f--)
            cout << a;
        for (int i = ch.size() - 1; i >= 0; i--)
        {
            cout << ch[i];
        }
    }
}

signed main()
{
    // int t_e_s_t;
    // cin>>t_e_s_t;
    // while(t_e_s_t--)
    // {
    inforkc();
    // }
    return 0;
}