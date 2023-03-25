#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int sum = 0, cnt = 0, i = 0, j = 0;
    while (j < n)
    {
        sum += v[j];
        while (sum > k)
        {
            sum -= v[i];
            i++;
        }
        if (sum == k)
            cnt++;
        j++;
    }
    cout << cnt << endl;
    return 0;
}
