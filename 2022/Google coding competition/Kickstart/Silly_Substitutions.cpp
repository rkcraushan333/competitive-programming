#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector<int>
const int mod = 1e9 + 7;
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return (t * t);
    else
        return (a * t * t);
}
// by inforkc
void inforkc()
{
    map<string, char> m;
    char c = '0';
    while (1)
    {
        string s = "";
        s += c;
        if (c == '9')
        {
            s += '0';
            m[s] = '1';
            break;
        }
        c++;
        s += c;
        if (c == '9')
            m[s] = '0';
        else
            m[s] = c + 1;
    }
    int n;
    string s;
    cin >> n >> s;
    stack<char> st;
    int i = 0;
    while (i < n)
    {
        if (st.size() > 0)
        {
            char temp = s[i];
            string t = "";
            t += st.top();
            t += temp;
            while (m.find(t) != m.end())
            {
                st.pop();
                temp = m[t];
                t = "";
                if (st.size() > 0)
                {
                    t += st.top();
                    t += temp;
                }
            }
            st.push(temp);
        }
        else
        {
            st.push(s[i]);
        }
        i++;
    }
    string ans = "";
    while (st.size() > 0)
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t_e_s_t;
    cin >> t_e_s_t;
    int i = 1;
    while (i <= t_e_s_t)
    {
        cout << "Case #" << i++ << ": ";
        inforkc();
    }
    return 0;
}