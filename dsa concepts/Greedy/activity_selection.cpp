#include <bits/stdc++.h>
using namespace std;

int maxActivities(int n, vector<pair<int, int>> v)
{
    if (n == 0)
        return 0;

    sort(v.begin(), v.end(), [&](pair<int, int> &a, pair<int, int> &b) { // Lymbda function
        return a.second < b.second;
    });

    int res = 1;
    int prev = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= v[prev].second)
        {
            res++;
            prev = i;
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    cout << maxActivities(n, v);
    return 0;
}