#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
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
signed main()
{

    int n;
    cin >> n;
    cout << (fastpow(2, n) - 1) * 2 << endl;
    return 0;
}