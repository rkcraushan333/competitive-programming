#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define v64 vector<ll>
#define p64 pair<ll, ll>
#define p64 pair<ll, ll>
const int mod = 1e9 + 7;
vector<pair<ll, ll>> pf(ll n)
{
    vector<pair<ll, ll>> ans;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            pair<ll, ll> p;
            p.first = i;
            p.second = cnt;
            ans.push_back(p);
        }
    }
    if (n > 1)
    {
        pair<ll, ll> p;
        p.first = n;
        p.second = 1;
        ans.push_back(p);
    }
    return ans;
}
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return (t * t);
    else
        return (a * t * t);
}
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Oredered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
// by inforkc
void f(int S,
       int X)
{
    int A = (S - X) / 2;

    int a = 0, b = 0;
    for (int i = 0; i < 5; i++)
    {
        // check
    }
    for (int i = 0; i < 8 * sizeof(S); i++)
    {
        unsigned long int Xi = (X & (1 << i));
        unsigned long int Ai = (A & (1 << i));
        if (Xi == 0 && Ai == 0)
        {
            continue;
        }
        else if (Xi == 0 && Ai > 0)
        {
            a = ((1 << i) | a);
            b = ((1 << i) | b);
        }
        else if (Xi > 0 && Ai == 0)
        {
            a = ((1 << i) | a);
        }
    }
    if (S == a + b && X == a ^ b)
        cout << a << " " << b << endl;
    else
        cout << -1 << endl;
}

void inforkc()
{
    for (int i = 0; i < 5; i++)
    {
        // check
    }
    int n;
    cin >> n;
    f(2 * n, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    int t_e_s_t;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        for (int i = 0; i < 5; i++)
        {
            // check
        }

        inforkc();
    }
    return 0;
}