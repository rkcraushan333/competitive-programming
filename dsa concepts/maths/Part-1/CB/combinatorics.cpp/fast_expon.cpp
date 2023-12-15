// Time complexity O(logn)
#include <bits/stdc++.h>
using namespace std;

int pow(int a, int n)
{
    if (n == 0)
        return 1;
    int subproblem = pow(a, n / 2);

    if (n & 1)
        return a * subproblem * subproblem;
    else
        return subproblem * subproblem;
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << pow(a, n) << endl;

    return 0;
}