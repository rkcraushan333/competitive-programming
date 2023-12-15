#include <bits/stdc++.h>
using namespace std;

// by inforkc

vector<int> merge(vector<int> &left, vector<int> &right)
{
    int n = left.size(), m = right.size(), i = 0, j = 0;
    vector<int> v;
    while (i < n && j < m)
        if (left[i] <= right[j])
            v.push_back(left[i++]);
        else
            v.push_back(right[j++]);
    while (i < n)
        v.push_back(left[i++]);
    while (j < m)
        v.push_back(right[j++]);

    return v;
}

void merge_sort(vector<int> &v)
{
    int n = v.size();
    if (n < 2)
        return;
    vector<int> left, right;
    for (int i = 0; i < n / 2; i++)
        left.push_back(v[i]);

    for (int i = n / 2; i < n; i++)
        right.push_back(v[i]);

    merge_sort(left);
    merge_sort(right);
    v = merge(left, right);
}
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    merge_sort(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}