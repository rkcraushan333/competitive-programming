#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            v[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 2)
        {

            cout << i << " "; //printing prime nos
        }
    }

    return 0;
}