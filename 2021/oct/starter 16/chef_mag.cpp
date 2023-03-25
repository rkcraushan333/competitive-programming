#include <bits/stdc++.h>
using namespace std;
#define int long

bool check(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int count = 0;
        int temp = x;
        while (temp++ != y)
        {
            count++;
            while (check(temp+2))
            {
                count--;
            }
            
        }
        cout<<count<<endl;
    }
    return 0;
}