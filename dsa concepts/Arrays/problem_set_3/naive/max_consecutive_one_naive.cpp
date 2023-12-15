#include <bits/stdc++.h>
using namespace std;
int max_one(bool arr[], int n)
{
    int res = 0, count;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 1)
                count++;
            else
                break;
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