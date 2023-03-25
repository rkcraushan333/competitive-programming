#include <bits/stdc++.h>
using namespace std;
#define int long long
// by inforkc
void inforkc()
{
    int a, b;
    cin >> a >> b;
    int r = (2 * a) + 1, c = (2 * b) + 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((i == 0 && j == 1) || (i == 0 && j == 0) || (i == 1 && j == 0) || (i == 1 && j == 1))
                cout << ".";
            else if (i % 2 == 0)
            {
                if (j & 1)
                    cout << "-";
                else
                    cout << "+";
            }
            else
            {
                if (j & 1)
                {
                    cout << ".";
                }
                else
                    cout << "|";
            }
        }
        cout << endl;
    }
}

signed main()
{
    int t_e_s_t;
    cin >> t_e_s_t;
    int i = 1;
    while (t_e_s_t--)
    {
        cout << "Case "
             << "#" << i++ << ":" << endl;
        inforkc();
    }
    return 0;
}