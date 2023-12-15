// Time complexity O(n)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(int arr[], int n)
{
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[count - 1])
        {
            arr[count++] = arr[i];
        }
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
    int count = removeDuplicates(arr, n);
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}