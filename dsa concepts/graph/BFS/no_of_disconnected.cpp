#include <bits/stdc++.h>
using namespace std;

// by inforkc
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void bfs(vector<int> adj[], int k, bool visited[])
{
    queue<int> q;
    q.push(k);
    visited[k] = true;
    while (!q.empty())
    {
        int u = q.front();
        // cout << u << " ";
        q.pop();
        for (auto e : adj[u])
        {
            if (!visited[e])
            {
                visited[e] = true;
                q.push(e);
            }
        }
    }
}
int bfsDis(vector<int> adj[], int v)
{
    int count = 0;
    bool visited[v + 1] = {0};
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            count++;
            bfs(adj, i, visited);
        }
    }
    return count;
}
int main()
{

    int v = 8;
    vector<int> adj[v];
    addEdge(adj, 0, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 6);
    addEdge(adj, 7, 7);

    cout << bfsDis(adj, v);

    return 0;
}