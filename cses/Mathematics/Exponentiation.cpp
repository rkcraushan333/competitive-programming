#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
// by inforkc
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return ((t % mod) * (t % mod)) % mod;
    else
        return ((a % mod) * (((t % mod) * (t % mod)) % mod)) % mod;
}
signed main()
{

    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << fastpow(a, b) << endl;
    }
    return 0;
}