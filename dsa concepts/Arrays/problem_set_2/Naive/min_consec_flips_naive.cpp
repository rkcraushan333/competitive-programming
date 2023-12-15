#include <bits/stdc++.h>
using namespace std;
void min_consec_flips(bool arr[], int n)
{
    int one = 0, zero = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0 && arr[i - 1] == 1)
        {
            one++;
        }
        if (arr[i] == 1 && arr[i - 1] == 0)
        {
            zero++;
        }
    }
    if (arr[n - 1] == 0)
        zero++;
    else
        one++;
    if (zero <= one)
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] == 0 && arr[i] == 1)
            {
                cout << "from " << i - 1 << " to ";
            }
            else if (arr[i - 1] == 1 && arr[i] == 0)
            {
                cout << i - 1 << endl;
            }
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] == 1 && arr[i] == 0)
            {
                cout << "from " << i - 1 << " to ";
            }
            else if (arr[i - 1] == 0 && arr[i] == 1)
            {
                cout << i - 1 << endl;
            }
        }
    }
}
int main()
{

    int n;
    cin >> n;
    bool arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    min_consec_flips(arr, n);
    return 0;
}