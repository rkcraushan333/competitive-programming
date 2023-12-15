#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int dp[10001][5001];
bool f(int i, int x, vector<int> &v)
{
    if (x == 0)
        return true;
    if (i < 0)
        return false;
    if (dp[x][i] != -1)
        return dp[x][i];
    if (x >= v[i])
    {
        if (f(i - 1, x - v[i], v) || f(i - 1, x, v))
            return dp[x][i] = true;
    }
    else
    {
        if (f(i - 1, x, v))
            return dp[x][i] = true;
    }
    return dp[x][i] = false;
}
signed main()
{
    memset(dp, -1, sizeof(dp));
    vector<int> v;
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        while (b--)
            v.push_back(a);
    }
    if (f(v.size() - 1, x, v))
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No";
    return 0;
}