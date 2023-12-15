#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int n;
    cin >> n;
    set<int> s;
    while (n--)
    {
        int k;
        cin >> k;
        s.insert(k);
    }
    cout << s.size();
}

signed main()
{
    // int t_e_s_t;
    // cin>>t_e_s_t;
    // while(t_e_s_t--)
    // {
    inforkc();
    // }
    return 0;
}