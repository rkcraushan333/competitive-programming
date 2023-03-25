#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < s.length() - 1; j++)
            {
                if (int(s[j]) > int(s[j + 1]))
                {
                    char temp;
                    temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum += ((i + 1) * (s[i] - 96));
        }
        cout << sum << endl;
    }
    return 0;
}