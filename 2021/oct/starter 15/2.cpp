#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    vector<int> v[t];

    int result[t];

    for (int i = 0; i < t; i++)
    {
        int n, m, k;
        cin >> n >> m >> k;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
        int l = 0;
        for (auto it = v[i].begin(); it <= v[i].end(); ++it)
        {
            if (*it == 0)
                break;

            l++;
        }
        if (l == n)
        {
            result[i] = 100;
        }
        else if (l == m)
        {
            result[i] = k;
        }
        else
        {
            result[i] = 0;
        }
    }
    for (int i = 0; i < t; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}