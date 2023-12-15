// Time complexity O(n)   (Using Kadane's algorithm)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int max_even_odd(int arr[], int n)
{
    int res = 1, count = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))

            count++;
        else
            count = 1;
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
    cout << max_even_odd(arr, n);
    return 0;
}