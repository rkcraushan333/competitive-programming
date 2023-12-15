#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
const int mod = 1e9 + 7;
vector<pair<int, int>> pf(int n)
{
    vector<pair<int, int>> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            pair<int, int> p;
            p.first = i;
            p.second = cnt;
            ans.push_back(p);
        }
    }
    if (n > 1)
    {
        pair<int, int> p;
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
void inforkc()
{
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> a(n), b(n);
    vector<pair<int, int>> v1, v2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v1.push_back({a[i] - w, a[i] + w});
        cout << v1[i].first << " " << v1[i].second << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        v2.push_back({b[i] - h, b[i] + h});
        // cout << v2[i].first << " " << v2[i].second << endl;
    }
    int k = 0, t = 0;
    for (int i = 0; i < n; i++)
    {
    }
    cout << "YES" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    int t_e_s_t;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}