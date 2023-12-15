// Fermat's little theorm(waorks when m is prime)
#include <bits/stdc++.h>
using namespace std;
bool check(int a, int b, int m)
{
    return (a - b) % m == ((a % m) - (b % m) + m) % m;
}
int binExpItr(int a, int b, int m)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a)%m;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int a, b, m;
    cin >> a >> b;
    int res1 = (a / b) % m;
    a = a%m;
    int inv_b = binExpItr(b, m - 2, m);
    int res2 = a * (inv_b % m); 
    cout << check(res1, res2, m);
    return 0;
}