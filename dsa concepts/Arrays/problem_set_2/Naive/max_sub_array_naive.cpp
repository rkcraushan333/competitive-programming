// Time complexity O(n^2)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int max_subArray_sum(int arr[], int n)
{
    int res = arr[0], curr;
    for (int i = 0; i < n; i++)
    {
        curr = 0;
        for (int j = i; j < n; j++)
        {
            curr = curr + arr[j];
            res = max(curr, res);
        }
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