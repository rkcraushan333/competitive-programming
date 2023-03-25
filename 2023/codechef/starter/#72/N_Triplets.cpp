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
    cin >> n;
    vec v;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (i * i == n)
            v.push_back(i);
        else if (n % i == 0)
        {
            v.push_back(i);
            v.push_back(n / i);
        }
    }
    int k = v.size();
    if (k < 3)
    {
        cout << -1 << endl;
        return;
    }
    sort(v.begin(), v.end());
    // for (int i = 0; i < k; i++)
    // {
    //     cout << v[i] << " ";
    // }
    int a = v[0], c = v[1], b = n / (a * c);
    if (a == b || b == c || c == a)
    {
        cout << -1 << endl;
        return;
    }
    cout << c << " " << b << " " << a << endl;
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