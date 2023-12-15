// Time complexity O(n^2)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int trappingWater(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        int lmax = arr[i], rmax = arr[i];
        for (int j = 0; j < i; j++)
        {
            lmax = max(lmax, arr[j]);
        }
        for (int j = i + 1; j < n; j++)
        {
            rmax = max(rmax, arr[j]);
        }
        res += (min(lmax, rmax) - arr[i]);
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
    cout << trappingWater(arr, n);
    return 0;
}