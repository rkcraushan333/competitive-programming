// Moore's voting algorithm
#include <bits/stdc++.h>
using namespace std;
int majorityElement(const vector<int> &A)
{
    int n = A.size();
    int count = 0, maj;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            maj = A[i];
        }
        else
        {
            if (A[i] == maj)
                count++;
            else
                count--;
        }
    }
    return maj;
}
// by inforkc
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << majorityElement(v);
    return 0;
}