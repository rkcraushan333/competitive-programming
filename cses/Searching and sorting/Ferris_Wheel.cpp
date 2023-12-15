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
    ll n, x;
    cin >> n >> x;
    vli v(n);
    REP(i, 0, n)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll aa = 0, bb = n - 1, count = 0;
    while (aa <= bb)
    {
        if (v[aa] + v[bb] <= x)
        {
            aa++;
            bb--;
            count++;
        }
        else
        {
            bb--;
            count++;
        }
    }
    cout << count << endl;
}

int main()
{

    inforkc();
    return 0;
}