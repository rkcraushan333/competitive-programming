// recursion
#include <bits/stdc++.h>
using namespace std;
int stock_buy(int arr[], int start, int end)
{
    if (end <= start)
    {
        return 0;
    }
    int profit = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (arr[j] > arr[i])
            {
                int curr_profit = (arr[j] - arr[i]) + stock_buy(arr, start, i - 1) + stock_buy(arr, j + 1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
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
    cout << stock_buy(arr, 0, n - 1);
    return 0;
}