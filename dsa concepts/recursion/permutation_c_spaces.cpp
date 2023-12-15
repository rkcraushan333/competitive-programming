#include <bits/stdc++.h>
using namespace std;
void permut(string s, int n, int i = 1)
{
    if (n == 0)
    {
        cout << s << endl;
        return;
    }
    string op1, op2;
    op1 = s;
    op2 = s.insert(i, "_");
    permut(op1, n - 1, i + 1);
    permut(op2, n - 1, i + 2);
}
int main()
{

    string s;
    cin >> s;
    permut(s, s.length() - 1);
    return 0;
}