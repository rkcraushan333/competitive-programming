// Time complexity O(logn)  {NOT GETTING OUTPUT FOR ODD INDICES}
// Auxiliary space O(logn)
#include <bits/stdc++.h>
using namespace std;
int binary_search_rec(int arr[], int low, int high, int x)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] < x)
    {
        return binary_search_rec(arr, mid + 1, high, x);
    }
    else
    {
        return binary_search_rec(arr, low, mid - 1, x);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cin >> x;
    cout << binary_search_rec(arr, 0, n - 1, x);
    return 0;
}