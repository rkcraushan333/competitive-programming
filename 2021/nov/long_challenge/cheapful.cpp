#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if ((a + k * c) > (b + k * d))
        {
            cout << "DIESEL\n";
        }
        else if ((a + k * c) < (b + k * d))
        {
            cout << "PETROL\n";
        }
        else
        {
            cout << "SAME PRICE\n";
        }
    }
    return 0;
}