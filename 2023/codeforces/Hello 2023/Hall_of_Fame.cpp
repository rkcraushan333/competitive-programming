#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
const int mod = 1e9 + 7;
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return (t * t);
    else
        return (a * t * t);
}
// by inforkc
void inforkc()
{
    int n;
    string s;
    cin >> n >> s;
    set<char> S;
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            if (s[i] == 'L' && s[i + 1] == 'R')
            {
                cout << i + 1 << endl;
                return;
            }
        }
        if (s[i] == 'L' && S.find('R') != S.end())
        {
            cout << 0 << endl;
            return;
        }
        S.insert(s[i]);
    }
    cout << -1 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    int t_e_s_t;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}