#include <bits/stdc++.h>
using namespace std;
void subset(string ip, string op = "")
{
    if (ip.empty())
    {
        cout << op << " ";
        return;
    }
    string op1 = op, op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    subset(ip, op1);
    subset(ip, op2);
}
int main()
{

    string s;
    cin >> s;
    subset(s);
    return 0;
}