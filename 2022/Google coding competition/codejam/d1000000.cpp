#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int n, k = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int count = 0, j = 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= j)
        {
            count++;
            j++;
        }
    }
    cout << count << endl;
}

signed main()
{
    int t_e_s_t;
    cin >> t_e_s_t;
    int i = 1;
    while (t_e_s_t--)
    {
        cout << "Case "
             << "#" << i++ << ": ";
        inforkc();
    }
    return 0;
}