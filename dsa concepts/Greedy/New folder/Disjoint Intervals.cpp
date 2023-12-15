#include <bits/stdc++.h>
using namespace std;

// by inforkc
bool compare(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
int disjoin(vector<vector<int>> &v)
{
    sort(v.begin(), v.end(), compare);
    int res = 1, prev = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[prev][1] < v[i][0])
        {
            prev = i;
            res++;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> v;
    v = {
        {1, 4},
        {2, 3},
        {4, 6},
        {8, 9}};
    cout << disjoin(v);
    return 0;
}