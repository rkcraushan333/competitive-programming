#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int a, b;
    cin >> a >> b;
    int ans = pow(a, b) + pow(b, a) ;
    cout <<ans << endl;
    return 0;
}