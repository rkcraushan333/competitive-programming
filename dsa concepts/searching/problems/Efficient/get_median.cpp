#include <bits/stdc++.h>
using namespace std;
int get_median(int *a, int *b, int n1, int n2)
{
    int i1 = n1 / 2;
    int i2 = ((n1 + n2 + 1) / 2) - i1;
    int low = i2, high = n1 - 1;
    while (a[i1] < b[i2 - 1])
    {
        }
}
int main()
{

    int a1[5] = {10, 20, 30, 40, 50};
    int a2[10] = {5, 15, 25, 30, 35, 55, 65, 75, 85};
    get_median(a1, a2, 5, 10);
    return 0;
}