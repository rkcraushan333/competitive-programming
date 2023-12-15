// using recursion in O(logn) print in modulo of 1e9+7
#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
int bin_exp(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int k = bin_exp(a,b/2);
    if (b & 1)
    {
        return (a * (k*1ll*k)%m)%m;
    }
    else
    {
        return (k*1ll*k)%m;
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << bin_exp(a, b);
    return 0;
}