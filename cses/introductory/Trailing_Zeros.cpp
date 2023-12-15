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
void inforkc()
{
    ll n;
    cin >> n;
    ll i = 5, res = 0;
    while (i <= n)
    {
        res += n / i;
        i *= 5;
    }
    cout << res << endl;
}

int main()
{
    // int t_e_s_t;
    // cin>>t_e_s_t;
    // while(t_e_s_t--)
    // {
    inforkc();
    // }
    return 0;
}