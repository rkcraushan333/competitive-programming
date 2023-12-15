#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
const int mod = 1e9 + 7;

void inforkc()
{
    int a, b;
    cin >> a >> b;
    int k = __gcd(a, b);
    cout << (a * k) / __gcd(a, k) - __gcd(b, k) << endl;
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