#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v[n];
    for (int i = 0; i < n; i++)
    {
        int no_of_elem;
        cin >> no_of_elem;
        for (int i = 0; i < no_of_elem; i++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    int query[q];
    for (int i = 0; i < q; i++)
    {
        cin >> query[i];
    }
    int result[q];
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;

        for (auto it = v[query[i]].begin(); it != v[query[i]].end(); ++it)
        {
            result[i] = *it;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << result[i];
    }

    return 0;
}