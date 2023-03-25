#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, final = 0, less = 0, larger = 0;
        cin >> n;
        int scores[n];
        for (int i = 0; i < n; i++)
        {
            cin >> scores[i];
        }
        for (int i = 0; i < n; i++)
        {
            less = 0;
            larger = 0;
            for (int j = 0; j < n; j++)
            {
                if (scores[i] >= scores[j])
                {
                    less++;
                }
                else
                {
                    larger++;
                }
            }
            if (less > larger)
            {
                final++;
            }
        }
        cout<<final<<endl;
    }

    return 0;
}