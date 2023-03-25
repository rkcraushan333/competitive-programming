#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int a = A[0] & A[1];

        cout << a << " ";
        for (size_t i = 0; i < n - 2; i++)
        {
            int c1 = A[i + 1] & A[i];
            int c2 = A[i + 1] & A[i + 2];
            if (c1 > c2)
            {
                cout << c1 << " ";
            }
            else
            {
                cout << c2 << " ";
            }
        }
        a = A[n - 2] & A[n - 1];
        cout << a << endl;
    }
    return 0;
}