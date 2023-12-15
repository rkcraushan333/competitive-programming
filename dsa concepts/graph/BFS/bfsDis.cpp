// disconnected graph

#include <bits/stdc++.h>
using namespace std;

// by inforkc
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void bfsDis(vector<int> adj[], int k, bool visited[])
{
    queue<int> q;
    q.push(k);
    visited[k] = true;
    while (q.empty() == false)
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (auto e : adj[u])
        {
            if (visited[e] == false)
            {
                visited[e] = true;
                q.push(e);
            }
        }
    }
}
int main()
{
    int v = 7;
    vector<int> adj[v];
    bool visited[v + 1] = {0};
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 6);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            bfsDis(adj, i, visited);
    }
    return 0;
}