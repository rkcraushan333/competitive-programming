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
bool isPalindrome(string s)
{
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}
void inforkc()
{
    int n;
    string s;
    cin >> n >> s;
    if (n < 3)
    {
        cout << s[0] << endl;
        return;
    }
    for (int i = 1; i < n - 2; i++)
    {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i, n - i);
        if (isPalindrome(s1) && isPalindrome(s2))
        {
            cout << s1 << endl;
            a return;
        }
    }
    cout << s << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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