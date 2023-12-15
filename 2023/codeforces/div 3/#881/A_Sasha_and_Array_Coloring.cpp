#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define v64 vector<int>
#define vp64 vector<pair<int, int>>
#define p64 pair<int, int>
#define forn(i, a, b) for (int i = a; i < b; i++)
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define pqmax priority_queue<int>
#define um unordered_map<int, int>
#define us unordered_set<int>
#define pb push_back
#define ln "\n"
#define yy cout << "Yes" << ln
#define nn cout << "No" << ln
#define pi 3.14159265358979323846
#define rsz resize
#define inc(v) sort(v.begin(), v.end())
#define dec(v) sort(v.rbegin(), v.rend())
const int mod = 1e9 + 7;
#define dbg cout << "debug" << ln;
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> T;
// Ordered set functions user less_equal for multiset
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
///////// TRIE TEMPLATE
class TrieNode
{
public:
    TrieNode *child[26];
    bool flag;
    TrieNode()
    {
        flag = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
    bool check(char c)
    {
        return (child[c - 'a'] != NULL);
    }
    void put(char c, TrieNode *node)
    {
        child[c - 'a'] = node;
    }
    TrieNode *get(char c)
    {
        return child[c - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isLast()
    {
        return flag;
    }
};
class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *node = root;
        for (auto &i : word)
        {
            if (!(node->check(i)))
            {
                node->put(i, new TrieNode());
            }
            node = node->get(i);
        }
        node->setEnd();
    }
    bool search(string word)
    {
        TrieNode *node = root;
        for (auto &i : word)
        {
            if (!(node->check(i)))
            {
                return false;
            }
            node = node->get(i);
        }
        return node->isLast();
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (auto &i : prefix)
        {
            if (!(node->check(i)))
                return false;
            node = node->get(i);
        }
        return true;
    }
};
///////////////// End of Trie Template
int fac[1000001];
void factorial()
{
    fac[0] = fac[1] = 1;
    forn(i, 2, 1000001)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
}
int pows[1000001];
bool done = 0;
int power10(int n)
{
    if (!done)
    {
        pows[0] = 1;
        for (int i = 1; i <= 1000000; i++)
            pows[i] = (pows[i - 1] * 10LL) % mod;
        done = 1;
    }
    return pows[n];
}
vector<int> prime;
void sieve()
{
    prime.resize(1e6 + 1);
    for (int i = 0; i < prime.size(); i++)
    {
        prime[i] = i;
    }
    for (int i = 2; i <= 1e6; i++)
    {
        if (prime[i] == i)
        {
            for (int j = 2 * i; j <= 1e6; j += i)
            {
                prime[j] = i;
            }
        }
    }
}
v64 primefac(int n)
{
    v64 res;
    while (n != prime[n])
    {
        res.push_back(prime[n]);
        n /= prime[n];
    }
    if (n != 1)
        res.push_back(n);
    return res;
}
int fastexpo(int a, int b, int m)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int fastpow(int a, int b)
{
    if (b == 0)
        return 1;
    int t = fastpow(a, b / 2);
    if (b % 2 == 0)
        return t * t;
    else
        return a * (t * t);
}

// for inverse modulo (k^mod-2)%mod
// by inforkc
void inforkc()
{
    int n;
    cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    inc(v);
    int i = 0, j = n - 1;
    int ans = 0;
    while (j > i)
    {
        ans += (v[j] - v[i]);
        j--;
        i++;
    }
    cout << ans << ln;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // sieve();
    // factorial();
    int t_e_s_t = 1;
    cin >> t_e_s_t;
    while (t_e_s_t--)
    {
        inforkc();
    }
    return 0;
}