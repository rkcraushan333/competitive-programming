#include <bits/stdc++.h>
using namespace std;

bool check(char *dir, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (dir[i] == 'L' && dir[i + 1] == 'L')
        {
            return true;
        }
        else if (dir[i] == 'R' && dir[i + 1] == 'R')
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char dir[n];
        bool k;
        k = check(dir, n);
        if (k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}