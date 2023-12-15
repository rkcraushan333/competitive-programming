// Time complexity O(n^2)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;

int getLargest(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            return i;
        }
    }
    return -1;
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
    cout << getLargest(arr, n);
    return 0;
}