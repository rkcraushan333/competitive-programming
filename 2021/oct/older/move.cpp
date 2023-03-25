#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{

    int n;
    cin >> n;
    string move[n];
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int c = abs(x - y);
        if (c % 2 == 0)
        {
            move[i] = "YES";
        }
        else{
            move[i] = "NO";
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<move[i]<<endl;
    }
    
    return 0;
}
