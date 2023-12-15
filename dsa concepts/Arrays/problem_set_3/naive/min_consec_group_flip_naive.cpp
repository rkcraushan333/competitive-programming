// Time complexity O(n)  {Not exact questions}
// Auxiliary space O(1)
#include <bits/stdc++.h>
using namespace std;
int min_flip(bool arr[], int n)
{
    int one = 0, zero = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zero++;
            one = 0;
        }
        else
        {
            one++;
            zero = 0;
        }
        if (zero == 0 && one == 1)
        {
            c2++;
        }
        if (one == 0 && zero == 1)
        {
            c1++;
        }
    }
    return min(c1, c2);
}
int main()
{

    int n;
    cin >> n;
    bool arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << min_flip(arr, n);
    return 0;
}