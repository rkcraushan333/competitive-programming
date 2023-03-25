#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
const int mod = 1e9 + 7;
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
// by inforkc
void inforkc()
{
    int n, cnt = 0;
    cin >> n;
    vec v(n);
    vector<bool> b1(n + 1, 0), b2(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>> p1, p2, q1, q2;
    map<int, int> m1, m2;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
    {
        if (!b1[v[i]])
        {
            b1[v[i]] = true;
            p1.push(v[i]);
            m1[v[i]] = i + 1;
        }
        else if (!b2[v[i]])
        {
            b2[v[i]] = true;
            p2.push(v[i]);
            m2[v[i]] = i + 1;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!b1[i])
            q1.push(i);
        if (!b2[i])
            q2.push(i);
    }
    vector<int> res1(n + 1), res2(n + 1);
    while (p1.size() > 0)
    {
        int k = p1.top();
        res1[m1[k]] = k;
        res2[m1[k]] = q2.top();
        p1.pop();
        q2.pop();
    }
    while (p2.size() > 0)
    {
        int k = p2.top();
        res2[m2[k]] = k;
        res1[m2[k]] = q1.top();
        p2.pop();
        q1.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i - 1] != max(res1[i], res2[i]))
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << res1[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << res2[i] << " ";
    cout << endl;
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