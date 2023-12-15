#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second / a.first) > (b.second / b.first);
}
double knapsack(int n, vector<pair<int, int>> v, int weight)
{
    sort(v.begin(), v.end(), [&](pair<int, int> &a, pair<int, int> &b) { // lymbda function
        return (a.second / a.first) > (b.second / b.first);
    });
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        if (weight >= v[i].first)
        {
            res += v[i].second;
            weight -= v[i].first;
        }
        else
        {
            res += (v[i].second * ((double)weight / v[i].first));
            return res;
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
    int weight;
    cin >> weight;
    cout << knapsack(n, v, weight);
    return 0;
}