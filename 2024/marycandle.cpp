#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int solution(int n, int k, vector<int> &candle)
{
    unordered_map<int, int> mp;
    int i = 0, j = 0, ans = INT_MAX;
    while (j < n)
    {
        if (candle[j] <= k)
        {
            mp[candle[j]]++;
        }
        while (i < j && mp.size() == k)
        {
            ans = min(ans, j - i + 1);
            if (candle[i] <= k)
            {
                mp[candle[i]]--;
                if (mp[candle[i]] == 0)
                {
                    mp.erase(candle[i]);
                }
            }
            i++;
        }
        j++;
    }
    return ans;
}
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << solution(n, k, v);
    return 0;
}