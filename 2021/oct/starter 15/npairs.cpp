#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, count = 0;
        cin >> n;
        char s[n];
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j <= min(n - 1, i + 9); j++)
            {
                if (((j + 2) - (i + 1)) == abs(s[j + 1] - s[i]))
                {
                    count += 1;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}