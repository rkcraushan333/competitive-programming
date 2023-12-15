#include <bits/stdc++.h>
using namespace std;

double jobSequence(int n, vector<pair<int, int>> v)
{
    sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b)
         { return a.second > b.second; });

    for (int i = 0; i < n; i++)
    {
    }
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

    cout << jobSequence(n, v);
    return 0;
}