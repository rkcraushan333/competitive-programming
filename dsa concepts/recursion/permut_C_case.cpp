#include <bits/stdc++.h>
using namespace std;
void permut(string s, int i = 0)
{
    if (i == s.length())
    {
        cout << s << endl;
        return;
    }
    string op1, op2;
    op1 = s;
    s[i] -= 32;
    op2 = s;
    permut(op1, i + 1);
    permut(op2, i + 1);
}
int main()
{

    string s;
    cin >> s;
    permut(s);
    return 0;
}