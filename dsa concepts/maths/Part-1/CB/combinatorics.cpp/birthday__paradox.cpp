// FOR NON_LEAP YEAR
#include <bits/stdc++.h>
using namespace std;

int birthdayParadox(double p)
{
    if (p == 1)
        return 1;
    double ans = 1, i = 365;
    int count = 0;
    while (ans > p)
    {
        ans *= (i / 365);
        i--;
        count++;
    }
    return count;
}
int main()
{
    double p;
    cin >> p;
    cout << birthdayParadox(1 - (p / 100));
    return 0;
}