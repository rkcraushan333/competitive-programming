// using O(n) print in modulo of 1e9+7
#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;

int main()
{
    int a,b;
    cin>>a>>b;
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
        ans %= m;
    }
    cout<<ans;
    return 0;
}