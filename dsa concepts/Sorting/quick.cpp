#include <bits/stdc++.h>
using namespace std;

// by inforkc
int findPivot(vector<int> &v, int s, int e)
{
    int pivot = v[e];
    int last_big = s;
    for (int i = s; i < e; i++)
        if (v[i] <= pivot)
            swap(v[i], v[last_big++]);

    swap(v[last_big], v[e]);
    return last_big;
}
void quick_sort(vector<int> &v, int start, int end)
{
    // Base case of empty array or single value array
    if (start >= end)
        return;
    int pivotIndex = findPivot(v, start, end);
    quick_sort(v, start, pivotIndex - 1);
    quick_sort(v, pivotIndex + 1, end);
}
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    quick_sort(v, 0, n - 1);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}