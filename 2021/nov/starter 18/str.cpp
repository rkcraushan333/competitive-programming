#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char A[n], B[n];
        cin >> A >> B;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == B[i])
            {
                c++;
            }
            else if (A[i] < B[i])
            {
                c++;
                cout<<c<<endl;
                break;
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}