#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int n;
    cin >> n;
    if (n < 4 && n > 1)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    for (int i = 2; i <= n; i += 2)
        cout << i << " ";
    for (int i = 1; i <= n; i += 2)
        cout << i << " ";
}

signed main()
{
    inforkc();
    return 0;
}