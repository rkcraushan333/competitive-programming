#include <bits/stdc++.h>
using namespace std;

// by inforkc
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int r = 0;

    for (int i = 1; i < n; i++)
    {
        int temp = v[i];
        int e = i;
        while (e > 0 && v[e - 1] > temp)
        {
            v[e] = v[e - 1];
            r++;
            e--;
        }
        v[e] = temp;
    }
    cout << r << endl;
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}