#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int k, int i = 0)
{
    if (arr.size() == 1)
    {
        cout << arr[0];
        return;
    }
    i = ((k + i) % arr.size());
    arr.erase(arr.begin() + i);
    solve(arr, k, i);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;

    for (int i = 1; i <= n; i++)
        arr.push_back(i);
    solve(arr, k - 1);
    return 0;
}