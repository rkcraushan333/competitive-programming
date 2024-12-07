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
vector<long long> v;
void f(string s)
{
    v.push_back(stoll(s));
    char c = s[0];
    if (c != '1')
    {
        string t = s;
        c--;
        t.push_back(c);
        reverse(t.begin(), t.end());
        t.push_back(c);
        f(t);
    }
}
void inforkc()
{
    int a, b, m;
    cin >> a >> b >> m;
    int count = 0;
    for (auto i : v)
    {
        if (i >= a && i <= b)
        {
            if (i % m == 0)
            {
                count++;
            }
        }
    }
    cout << count << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 1; i <= 9; i++)
    {
        f(to_string(i));
    }

    int t_e_s_t;
    cin >> t_e_s_t;
    int i = 1;
    while (i <= t_e_s_t)
    {
        cout << "Case #" << i++ << ": ";
        inforkc();
    }
    return 0;
}