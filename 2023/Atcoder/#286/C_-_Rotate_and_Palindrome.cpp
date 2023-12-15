#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int palindrome(string s)
{
    int k = 0, n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            k++;
    }
    return k;
}
signed main()
{

    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    s += s;
    int ans = INT64_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, i * a + b * palindrome(s.substr(i, n)));
    }
    cout << ans << endl;
    return 0;
}