#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    set<int> h;
    int i = 0, j = 0, res = 1;
    while (j < n)
    {
        if (h.count(v[j]))
        {
            while (h.count(v[j]))
            {
                h.erase(v[i++]);
            }
        }
        h.insert(v[j++]);
        if (h.size() > res)
            res = h.size();
    }
    cout << res;
    return 0;
}