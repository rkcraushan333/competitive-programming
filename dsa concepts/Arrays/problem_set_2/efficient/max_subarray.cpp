// Time complexity O(n)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int max_subArray_sum(int arr[], int n)
{
    int res = arr[0], maxEnd = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxEnd = max(maxEnd + arr[i], arr[i]);
        res = max(res, maxEnd);
    }
    return res;
}
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << max_subArray_sum(arr, n);
    return 0;
}