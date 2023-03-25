#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (d >= (a + b + c))
        {
            arr[i] = 1;
        }
        else if (d < (a + b + c))
        {
            arr[i] = ceil((a + b + c) / float(d));
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}

