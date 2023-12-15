#include <bits/stdc++.h>
using namespace std;

// by inforkc
vector<int> solve(vector<int> &A, int B)
{
    int n = A.size();
    vector<int> v;
    v = A;
    sort(v.rbegin(), v.rend());
    if (B >= n - 1)
        return v;

    map<int, int> m1;
    map<int, int> m2;
    for (int i = 0; i < n; i++)
    {
        m1[i] = A[i];
        m2[A[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (B == 0)
            break;
        if (m1[i] != v[i])
        {
            int k1 = m1[i];
            m1[i] = v[i];
            int k2 = m2[v[i]];
            m2[v[i]] = i;
            m1[k2] = k1;
            m2[k1] = k2;
            B--;
        }
    }
    vector<int> vr;
    for (auto e : m2)
    {
        vr.push_back(e.first);
    }
    return vr;
}
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int b;
    cin >> b;
    vector<int> v1(n);
    v1 = solve(v1, b);
    for (int i = 0; i < n; i++)
        cout << v1[i] << " ";
    return 0;
}