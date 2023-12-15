// Time complexity O(n)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;

int getSecondLargest(int arr[], int n)
{
    int largest = 0;
    int res = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] < arr[largest])
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