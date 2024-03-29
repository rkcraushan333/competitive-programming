#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int f(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}
int f1(int n)
{
    int res = 0;
    while (n)
    {
        res = max(res, n % 10);
        n /= 10;
    }
    return res;
}
signed main()
{
    int n;
    cin >> n;
    int cnt = 1;
    while (f(n) > 1)
    {
        cnt++;
        n -= f1(n);
    }
    cout << cnt << endl;
    return 0;
}