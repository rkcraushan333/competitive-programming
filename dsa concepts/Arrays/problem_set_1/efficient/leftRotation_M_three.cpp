// Time complexity O(n) {Reversal Algorithm}
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
void reverseArray(int arr[], int low, int high)
{
    while (low < high)
    {
        int temp = arr[low];
        arr[low++] = arr[high];
        arr[high--] = temp;
    }
}
void rotateArray(int arr[], int n, int d)
{
    // 1. Reverse first d elements
    reverseArray(arr, 0, d - 1);
    // 2. Reverse remaining n-d elements
    reverseArray(arr, d, n - 1);
    // 3. Reverse the array
    reverseArray(arr, 0, n - 1);
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
    int d = 0;
    cin >> d;
    rotateArray(arr, n, d);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}