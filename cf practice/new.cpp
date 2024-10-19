#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
string solution(vector<int> &numbers, int pivot)
{
    int c1 = 0, c2 = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] < pivot)
        {
            c1++;
        }
        else if (numbers[i] > pivot)
        {
            c2++;
        }
    }
    if (c1 > c2)
    {
        return "smaller";
    }
    else if (c2 > c1)
    {
        return "greater";
    }
    return "tie";
}
signed main()
{
    return 0;
}