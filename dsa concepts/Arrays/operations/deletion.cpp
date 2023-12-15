// Time complexity O(n)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int deleteFile(int a[], int n, int key)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            break;
    }
    if (i == n)
        return n;
    for (int j = i; j < n - 1; j++)
    {
        a[j] = a[j + 1];
    }
    return n - 1;
}
int main()
{
    int arr[] = {1, 3, 4, 5, 7, 8};
    int x;
    cin >> x;
    int n = sizeof(arr) / sizeof(int);
    n = deleteFile(arr, n, x);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}