#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, l, x;
        cin >> n >> l >> x;
        cout << x * (min(l, n - l)) << endl;
    }
    return 0;
}