// Time complexity O(n)
// Auxiliary space O(n)
#include <bits/stdc++.h>
using namespace std;
int majority(int arr[], int n) // Murage voting algorithm
{
    int res = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
    }
    if (count <= n / 2)
        return -1;
    return res;
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