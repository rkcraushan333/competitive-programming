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
        cout << (min(l, n - l)) * x << endl;
    }
    return 0;
}