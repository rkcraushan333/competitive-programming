// Factorial of large numbers
#include <bits/stdc++.h>
using namespace std;
#define m 1000

int main()
{
    int arr[m];
    arr[0] = 1;
    int size = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < size; j++)
        {
            int product = arr[j] * i + carry;
            arr[j] = product % 10;
            carry = product / 10;
        }
        while (carry)
        {
            arr[size] = carry % 10;
            carry = carry / 10;
            size++;
        }
    }
    for (int j = size - 1; j >= 0; j--)
    {
        cout << arr[j];
    }

    return 0;
}