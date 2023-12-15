#include <bits/stdc++.h>
using namespace std;
int count_div(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (i != n / i)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << count_div(i) << endl;
    }

    return 0;
}