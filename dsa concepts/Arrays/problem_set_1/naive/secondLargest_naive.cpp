// Time complexity O(n) two traversal
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;

int getLargest(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[res])
        {
            res = i;
        }
    }
    return res;
}
int getSecondLargest(int arr[], int n)
{
    int largest = getLargest(arr, n);
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[largest])
        {
            if (res == -1 || arr[res] < arr[i])
                res = i;
        }
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
    cout << getSecondLargest(arr, n);
    return 0;
}