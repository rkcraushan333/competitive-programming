// Time complexity O(n^2)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int max_subArray_odd_even(int arr[], int n)
{
    int res = 0, count;
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] % 2 == 0 && arr[j - 1] % 2 != 0) || (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0))
                count++;
            else
                break;
        }
        res = max(res, count);
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
    cout << max_subArray_odd_even(arr, n);
    return 0;
}