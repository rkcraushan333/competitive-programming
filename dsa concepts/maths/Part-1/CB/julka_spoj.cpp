#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;

cpp_int main()
{
    cpp_int n, k, ans;
    cin >> n >> k;
    ans = (n - k) / 2;
    cout << ans << " " << ans + k << endl;
    return 0;
}