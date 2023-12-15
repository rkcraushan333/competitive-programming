#include <bits/stdc++.h>
using namespace std;

void deleteMid(stack<int> &s, int n, int t)
{
    if (t == n / 2)
    {
        s.pop();
        if (!(n & 1))
            s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    deleteMid(s, n, t - 1);
    s.push(temp);
}

int main()
{

    stack<int> s;
    s.push(5);
    s.push(3);
    s.push(2);
    // s.push(1);
    s.push(4);
    s.push(6);
    deleteMid(s, s.size(), s.size() - 1);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}