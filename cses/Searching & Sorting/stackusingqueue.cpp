#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
class st
{
    queue<int> q;

public:
    void push(int x)
    {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    int top()
    {
        return q.front();
    }
    int size()
    {
        return q.size();
    }
    void pop()
    {
        q.pop();
    }
};
signed main()
{
    st s;
    s.push(3);
    s.push(4);
    s.push(0);
    s.push(1);
    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}