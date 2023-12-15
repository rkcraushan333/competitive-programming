#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{

    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        st.insert(k);
    }
    if (st.size() == 1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}