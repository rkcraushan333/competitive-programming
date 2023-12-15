// Time complexity O(n)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;

int insert(int a[], int n, int cap, int key, int pos)
{
    if (cap == n)
        return n;

    int idx = pos - 1;
    for (int i = n - 1; i >= idx; i--)
    {
        a[i + 1] = a[i];
    }
    a[idx] = key;
    return n + 1;
}

int main()
{
    int arr[10] = {1, 3, 4, 5, 7, 8};
    int x, y;
    cin >> x >> y;
    int cap = sizeof(arr) / sizeof(int);
    int n = 6;
    n = insert(arr, 6, cap, x, y);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}