#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int n, in, k;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        k = upper_bound(v.begin(), v.end(), in) - v.begin();
        if (k == v.size())
            v.push_back(in);
        else
            v[k] = in;
    }
    cout << v.size() << endl;
}

signed main()
{
    inforkc();
    return 0;
}