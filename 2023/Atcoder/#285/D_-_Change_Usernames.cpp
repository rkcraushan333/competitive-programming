#include <bits/stdc++.h>
using namespace std;
#define int long long

// by inforkc
signed main()
{
    int n;
    cin >> n;
    unordered_map<string, int> hash;
    vector<pair<string, string>> v;
    int i = 0;
    while (n--)
    {
        string s, t;
        cin >> s >> t;
        if (hash.find(s) == hash.end())
            hash[s] = i++;
        if (hash.find(t) == hash.end())
            hash[t] = i++;
        v.push_back({s, t});
    }
    vector<int> adj[i];
    for (auto &x : v)
        adj[hash[x.first]].push_back(hash[x.second]);
    vector<int> topo, indegree(i);
    for (int x = 0; x < i; x++)
    {
        for (int j = 0; j < adj[x].size(); j++)
            indegree[adj[x][j]]++;
    }
    queue<int> q;
    for (int j = 0; j < i; j++)
    {
        if (indegree[j] == 0)
            q.push(j);
    }
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        topo.push_back(k);
        for (auto &j : adj[k])
        {
            indegree[j]--;
            if (indegree[j] == 0)
                q.push(j);
        }
    }
    if (topo.size() < i)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}