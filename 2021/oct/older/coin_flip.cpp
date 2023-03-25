#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int g;
        cin >> g;
        while (g--)
        {
            int I, N, Q;
            cin >> I >> N >> Q;
            int coins[N], coins2[N];
            if (I == 1)
            {
                for (int i = 0; i < N; i++)
                {
                    coins[i] = 1;
                    coins2[i] = 2;
                }
            }
            else
            {
                for (int i = 0; i < N; i++)
                {
                    coins[i] = 2;
                    coins2[i] = 1;
                }
            }
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    int temp = coins[j-1];
                    coins[j-1] = coins2[j-1];
                    coins2[j-1] = temp;
                }
            }
            int count = 0;
            if (Q == 1)
            {
                for (int i = 0; i < N; i++)
                {
                    if (coins[i] == 1)
                    {
                        count += 1;
                    }
                }
            }
            else
            {
                for (int i = 0; i < N; i++)
                {
                    if (coins[i] == 2)
                    {
                        count += 1;
                    }
                }
            }
            cout<<count<<endl;
        }
    }

    return 0;
}