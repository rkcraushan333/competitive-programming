#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define v64 vector<int>
#define vp64 vector<pair<int, int>>
#define p64 pair<int, int>
#define forn(i, a, b) for (int i = a; i < b; i++)
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define pqmax priority_queue<int>
#define um unordered_map<int, int>
#define us unordered_set<int>
#define pb push_back
#define ln "\n"
#define yy cout << "Yes" << ln
#define nn cout << "No" << ln
#define pi 3.14159265358979323846
#define rsz resize
#define inc(v) sort(v.begin(), v.end())
#define dec(v) sort(v.rbegin(), v.rend())
void inforkc()
{
    int n;
    cin >> n;
    int ap = 0, bp = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++)
    {
        string cd;
        cin >> cd;
        if (cd == "A")
            ap++;
        else if (cd == "B")
            bp++;
        else if (cd == "AB")
            c++;
        else
            d++;
    }
    int cc = 0;
    if (d)
        cc += d;
    int a = 0, b = 0;
    if (ap)
        a = ap;
    if (bp)
        b = bp;
    if (c)
        cc += c;
    if (a > b)
        cout << cc + a << ln;
    else
        cout << cc + b << ln;
}

signed main()
{

    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // sieve();
    // factorial();
    int t_e_s_t = 1;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}