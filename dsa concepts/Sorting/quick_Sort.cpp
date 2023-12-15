#include <bits/stdc++.h>
using namespace std;

// by inforkc
int partition(vector<int> &v, int s, int e)
{
    int c = s;
    for (int i = s; i < e; i++)
    {
        if (v[i] <= v[e])
            swap(v[i], v[c++]);
    }
    swap(v[c], v[e]);
    return c;
}

void quicksort(vector<int> &v, int s, int e)
{
    if (s >= e)
        return;
    int pIndex = partition(v, s, e);
    quicksort(v, s, pIndex - 1);
    quicksort(v, pIndex + 1, e);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    quicksort(v, 0, n - 1);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}