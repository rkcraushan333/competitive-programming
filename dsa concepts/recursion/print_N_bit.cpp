// print N bit numbers having  no of 1's >= no of 0's
#include <bits/stdc++.h>
using namespace std;

void printNbits(int n, int one = 0, int zero = 0, string s = "")
{
    if (n == 0)
    {
        cout << s << endl;
        return;
    }
    if (one > zero)
        printNbits(n - 1, one, zero + 1, s + "0");
    printNbits(n - 1, one + 1, zero, s + "1");
}

int main()
{
    int n;
    cin >> n;
    printNbits(n);
    return 0;
}