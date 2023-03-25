#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n;
    cin >> n;
    string match[n];
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (((2 * z) + x) >= y)
        {
            match[i] = "YES";
        }
        else
        {
            match[i] = "NO";
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << match[i] << endl;
    }
    return 0;
}
