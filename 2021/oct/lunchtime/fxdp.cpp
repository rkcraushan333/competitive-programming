#include <bits/stdc++.h>
using namespace std;

#define int long

signed main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin>>A[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (A[i] == i+1 )
                {
                    count++;
                }
                if (A[j] == j+1)
                {
                    count++;
                }
            }
            
        }
        cout<<count<<endl;
    }
    return 0;
}