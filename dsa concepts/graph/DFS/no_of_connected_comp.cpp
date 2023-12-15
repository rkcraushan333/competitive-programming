#include <bits/stdc++.h>
using namespace std;

// by inforkc
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfsRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = 1;
    // cout<<s<<" ";
    for (auto i : adj[s])
    {
        if (!visited[i])
            dfsRec(adj, i, visited);
    }
}
int connectedComponents(vector<int> adj[], int v)
{
    bool visited[v] = {0};
    int count = 0;
    for (int i = 0; i < v; ++i)
    {
        if (!visited[i])
        {
            count++;
            dfsRec(adj, i, visited);
        }
    }
    return count;
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
    cout << connectedComponents(adj, v);
    return 0;
}