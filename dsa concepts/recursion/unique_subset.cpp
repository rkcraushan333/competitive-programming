#include <bits/stdc++.h>
using namespace std;
unordered_set<string> m;
void subset(string ip, string op = "")
{
    if (ip.empty())
    {
        m.insert(op);
        return;
    }
    string op1 = op, op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    subset(ip, op1);
    subset(ip, op2);
}
void print()
{
    for (auto i : m)
    {
        cout << i << endl;
    }
}
int main()
{

    string s;
    cin >> s;
    subset(s);
    print();
    return 0;
}