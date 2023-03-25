#include <bits/stdc++.h>
using namespace std;

void check(int r, float t)
{

    if (r % 5 == 0 && r+0.5 <= t)
    {
        cout<<fixed<<setprecision(2) << t - r - 0.50;
    }
    else if (r+0.5 <= t && (r % 5 != 0))
    {
        cout<<fixed<<setprecision(2) << t;
    }
    else if (r+0.5 > t)
    {
        cout<<fixed<<setprecision(2) << t;
    }
}

int main()
{
    int r;
    float t;
    cin >> r >> t;
    check(r, t);
    return 0;
}
