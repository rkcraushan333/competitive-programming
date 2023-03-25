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
        int count = 0, l = 0, m = 0;
        for (int i = 0; i < n; i++)
        {
            int l = 0, m = 0;
            for (int j = 0; j < n; j++)
            {
                if (A[i] >= A[j])
                {
                    l++;
                }
                else
                {
                    m++;
                }
            }
            if (l > m)
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}