// Using Kahn's algorithm

#include <bits/stdc++.h>
using namespace std;

// by inforkc
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool cycle(vector<int> adj[], int v)
{
    int indegree[v] = {0};
    for (int i = 0; i < v; i++)
    {
        for (auto j : adj[i])
            indegree[j]++;
    }
    int count = 0;
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        count++;
        for (auto j : adj[u])
        {
            indegree[j]--;
            if (indegree[j] == 0)
                q.push(j);
        }
    }
    return count != v;
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(adj, a, b);
    }
    if (cycle(adj, v))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}