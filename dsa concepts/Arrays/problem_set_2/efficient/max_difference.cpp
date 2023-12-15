// Time complexity O(n)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int stock_buy(int arr[], int n)
{
    int res = arr[1] - arr[0], curr_min = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, arr[i] - curr_min);
        curr_min = min(curr_min, arr[i]);
    }
    return res;
}
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << stock_buy(arr, n);
    return 0;
}