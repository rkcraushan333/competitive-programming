#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef pair<int, int> pi;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a) * (a)
// by inforkc
ll finds(ll n)
{
    return (n * (n + 1)) / 2;
}
void inforkc()
{
    ll n, p;
    cin >> n;
    p = n;
    if (finds(n) & 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        ll k = finds(n) / 2;
        bool arr[p + 1];
        for (int i = 0; i <= p; i++)
        {
            arr[i] = 1;
        }
        arr[p] = 0;
        ll aa = n, count = 1;
        while (aa <= k)
        {
            n--;
            aa += n;

            arr[n] = 0;
            count++;
        }
        aa -= n;
        arr[n] = 1;
        if (aa == k)
        {
            count--;
            cout << count << endl;
            for (int i = 1; i <= p; i++)
            {
                if (!arr[i])
                {
                    cout << i << " ";
                }
            }
            cout << endl;
            cout << p - count << endl;
            for (int i = 1; i <= p; i++)
            {
                if (arr[i])
                {
                    cout << i << " ";
                }
            }
        }
        else
        {
            arr[k - aa] = 0;
            cout << count << endl;
            for (int i = 1; i <= p; i++)
            {
                if (!arr[i])
                {
                    cout << i << " ";
                }
            }
            cout << endl;
            cout << p - count << endl;
            for (int i = 1; i <= p; i++)
            {
                if (arr[i])
                {
                    cout << i << " ";
                }
            }
        }
    }
}

int main()
{
    // int t_e_s_t;
    // cin >> t_e_s_t;
    // while (t_e_s_t--)
    // {
    inforkc();
    // }
    return 0;
}