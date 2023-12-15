// Time complexity O(n)
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
void frequency(int arr[], int n)
{
    int count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            count++;
        }
        else
        {
            cout << arr[i] << " " << count << endl;
            count = 1;
        }
    }
    cout << arr[n - 1] << " " << count << endl;
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
    frequency(arr, n);
    return 0;
}