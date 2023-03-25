#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<bool> is_prime(5000001, true);
vector<int> v;
void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 5000001; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= 5000001; j += i)
                is_prime[j] = false;
        }
    }
}
// by inforkc
void inforkc()
{
    int n;
    cin >> n;
    for (auto &i : v)
    {
        int k = i * i;
        if (n % k == 0)
        {
            cout << i << " " << n / k << endl;
            return;
        }
        else if (n % i == 0)
        {
            int k = n / i;
            int t = sqrt(k);
            if (t * t == k)
            {
                cout << t << " " << i << endl;
                return;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    sieve();
    for (int i = 2; i <= 5000001; i++)
    {
        if (is_prime[i])
            v.push_back(i);
    }
    int t_e_s_t;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}