#include <bits/stdc++.h>
using namespace std;
int max_one(bool arr[], int n)
{
    int res = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        res = max(res, count);
    }
    return res;
}
int main()
{

    int n;
    cin >> n;
    bool arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << max_one(arr, n);
    return 0;
}