#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int x, y, z;
        cin>>x>>y>>z;
        if (x+y<=z)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        
        
    }
    return 0;
}