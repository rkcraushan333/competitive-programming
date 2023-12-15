#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v1(a);
    vector<int> v2(b);
    for (int i = 0; i < a; i++)
        cin >> v1[i];
    for (int i = 0; i < b; i++)
        cin >> v2[i];
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int aa = 0, bb = 0, count = 0;
    while ((aa < a) && (bb < b))
    {
        if ((v1[aa] >= (v2[bb] - c)) && (v1[aa] <= (v2[bb] + c)))
        {
            count++;
            aa++;
            bb++;
        }
        else
        {
            if (v1[aa] < v2[bb] - c)
                aa++;
            else
                bb++;
        }
    }
    cout << count << endl;
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