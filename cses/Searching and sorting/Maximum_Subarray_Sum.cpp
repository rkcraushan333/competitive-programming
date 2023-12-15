#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
const int mod = 1e9 + 7;
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return (t * t);
    else
        return (a * t * t);
}
// by inforkc
void inforkc()
{
    int n;
    cin >> n;
    int sum, prev;
    cin >> sum;
    prev = sum;
    for (int i = 1; i < n; i++)
    {
        int k;
        cin >> k;
        if (k > prev)
        {
            sum = k;
        }
        else if (prev + k >)
        {
        }
    }
    cout << sum;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool t = false;
    if (t)
    {
        int t_e_s_t;
        cin >> t_e_s_t;
        while (t_e_s_t--)
            inforkc();
    }
    else
        inforkc();
    return 0;
}