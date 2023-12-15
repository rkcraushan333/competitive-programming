// Time complexity O(n^2)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int max_circular_sum(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int last = arr[i];
        for (int j = 1; j < n; j++)
        {
            int ind = (i + j) % n;
            last += arr[ind];
            res = max(res, last);
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
    cout << max_circular_sum(arr, n);
    return 0;
}