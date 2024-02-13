#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
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
const int mod = 1e9 + 7;
#define dbg cout << "debug" << ln;
void solve()
{
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // sieve();
    // factorial();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        // solve();
        int n, m;
        cin >> n >> m;
        vector<int> temp(n);
        map<int, int> mp;
        int prev = 0;
        int prev_sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp[i];
            mp[i + 1] = temp[i];
            prev_sum += temp[i];
        }
        
        v64 result;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a;
            if (a == 2)
            {
                cin >> b;
                mp.clear();
                prev = b;
                result.push_back(b * n);
                prev_sum = b * n;
            }
            else
            {
                cin >> b >> c;
                if (mp.find(b) == mp.end())
                {
                    result.push_back(prev_sum + c - prev);
                    mp[b] = c;
                    prev_sum = prev_sum + c - prev;
                }
                else
                {
                    result.push_back(prev_sum + c - mp[b]);
                    mp[b] = c;
                    prev_sum = prev_sum + c - mp[b];
                }
            }
        }
        for (auto it : result)
            cout << it << endl;
        cout << endl;
    }
    return 0;
}