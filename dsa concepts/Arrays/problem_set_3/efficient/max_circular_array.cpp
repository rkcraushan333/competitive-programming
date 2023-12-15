// Time complexity O(n)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int normalmaxsum(int *arr, int n) // this is using Kadane algorithm
{
    int res = arr[0], prev = arr[0];
    for (int i = 1; i < n; i++)
    {
        prev = max(arr[i], prev + arr[i]);
        res = max(res, prev);
    }
    return res;
}
int overallsum(int arr[], int n)
{
    int max_normal = normalmaxsum(arr, n);
    if (max_normal < 0)
        return max_normal;
    int arr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = arr_sum + normalmaxsum(arr, n);
    return max(max_circular, max_normal);
}
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << overallsum(arr, n);
    return 0;
}