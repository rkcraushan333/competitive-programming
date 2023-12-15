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
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == 'a')
        {
            cout << s.substr(0, i) << " " << s.substr(i, 1) << " " << s.substr(i + 1, n - i - 1) << endl;
            return;
        }
    }
    cout << s.substr(0, 1) << " " << s.substr(1, n - 2) << " " << s.substr(n - 1, 1) << endl;
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