#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;

    cin >> a;
    while (a--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        n += 1;
        if (x > (n * y))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}