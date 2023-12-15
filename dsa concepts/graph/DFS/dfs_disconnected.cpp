#include <bits/stdc++.h>
using namespace std;

// by inforkc

void dfsRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (auto i : adj[s])
    {
        if (!visited[i])
            dfsRec(adj, i, visited);
    }
}

void dfsDis(vector<int> adj[], int v)
{
    bool visited[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            dfsRec(adj, i, visited);
        }
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{

    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < v; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(adj, a, b);
    }
    dfsDis(adj, v);
    return 0;
}