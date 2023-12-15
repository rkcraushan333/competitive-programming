// Time complexity O(n^2)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int majority(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > n / 2)
            return i;
    }
    return -1;
}
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << majority(arr, n);
    return 0;
}