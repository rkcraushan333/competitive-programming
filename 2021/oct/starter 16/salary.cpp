#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        string days;
        cin >> days;
        int real_salary = 0, a = 0, b = 0;
        for (int i = 0; i <= 30; i++)
        {
            if (days[i] == '1')
            {
                real_salary += 1;
                a += 1;
            }
            else{
                if (a > b)
                {
                    b = a;
                    a = 0;
                }
                else
                {
                    a = 0;
                }
                }
        }
        int total = ((real_salary * x) + (b*y));
        cout << total << endl;
    }
    return 0;
}