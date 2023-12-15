// using iterator (most efficient) in O(logn) print in modulo of 1e9+7
#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
int binExpItr(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1ll * a) % m;
        }
        b >>= 1;
        a *= a;
    }
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << binExpItr(a, b);
    return 0;
}