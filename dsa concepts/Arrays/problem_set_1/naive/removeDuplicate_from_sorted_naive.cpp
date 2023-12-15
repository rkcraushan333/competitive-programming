// Time complexity O(n)
// Auxiliary space O(n)
#include <bits/stdc++.h>
using namespace std;
int removeDuplicatedFromSorted(int arr[], int n)
{
    int temp[n];
    temp[0] = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != temp[count - 1])
        {
            temp[count++] = arr[i];
        }
    }
    for (int i = 0; i < count; i++)
    {
        arr[i] = temp[i];
    }
    return count;
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
    int count = removeDuplicatedFromSorted(arr, n);
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}