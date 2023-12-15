#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}
int minCoins(int n, vector<int> v, int amount)
{
    sort(v.begin(), v.end(), compare);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (amount >= v[i])
        {
            int c = amount / v[i];
            amount -= (c * v[i]);
            res += c;
        }
        if (amount == 0)
            break;
    }
    return res;
}

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int amount;
    cin >> amount;
    cout << minCoins(n, v, amount);
    return 0;
}