#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
int mod = 1e9 + 7;
// by inforkc
vector<int> v;
int f(int i = 0, int cnt = 0, int prev = 0)
{
    if (i == v.size())
    {
        if (cnt >= v.size() / 2 + 1)
            return 1;
        return 0;
    }
    if (v[i] & 1)
    {
        if (prev == 0)
        {
            int ans = 0;
            for (int j = 1; j <= 5; j++)
            {
                if (j & 1)
                    ans += f(i + 1, cnt, j);
                else
                    ans += f(i + 1, cnt + 1, j);
            }
            return ans;
        }
        else
        {
            int ans = 0;
            for (int j = 1; j <= 5; j++)
            {
                if (j != prev)
                {
                    if (j & 1)
                        ans += f(i + 1, cnt, j);
                    else
                        ans += f(i + 1, cnt + 1, j);
                }
            }
            return ans;
        }
    }
    else
    {
        if (prev == 0)
        {
            int ans = 0;
            for (int j = 1; j <= 5; j++)
            {
                if (j & 1)
                    ans += f(i + 1, cnt + 1, j);
                else
                    ans += f(i + 1, cnt, j);
            }
            return ans;
        }
        else
        {
            int ans = 0;
            for (int j = 1; j <= 5; j++)
            {
                if (j != prev)
                {
                    if (j & 1)
                        ans += f(i + 1, cnt + 1, j);
                    else
                        ans += f(i + 1, cnt, j);
                }
            }
            return ans;
        }
    }
}
void inforkc()
{
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    return f();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    int t_e_s_t = 1;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}