#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
int kmpPatternMatching(string &str, string &pattern)
{
    int n = str.size(), m = pattern.size();
    // finding prefix and suffix of pattern
    vector<int> v(m);
    int i = 0, j = 1;
    while (j < m)
    {
        if (pattern[i] == pattern[j])
        {
            v[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            while (i > 0 && (pattern[i] != pattern[j]))
            {
                i--;
                i = v[i];
            }
            if (pattern[i] != pattern[j])
            {
                j++;
            }
        }
    }
    int ans = 0;
    i = 0;
    j = 0;
    while (i < n)
    {
        if (str[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            while (j > 0 && (str[i] != pattern[j]))
            {
                j--;
                j = v[j];
            }
            if (str[i] != pattern[j])
            {
                i++;
            }
        }
        if (j == m)
        {
            ans++;
            while (j > 0 && (str[i] != pattern[j]))
            {
                j--;
                j = v[j];
            }
        }
    }
    return ans;
}
signed main()
{

    string s, p;
    cin >> s >> p;

    cout << kmpPatternMatching(s, p) << endl;
    return 0;
}