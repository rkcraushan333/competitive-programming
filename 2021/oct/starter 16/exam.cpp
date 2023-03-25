#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // test cases
    cin >> t;
    while (t--)
    {
        int n, x, p; // input
        cin >> n >> x >> p;
        int result = ((x * 3) - (n - x));
        if (result >= p)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    }
    return 0;
}