// for a given source and all vertices are accessible using source
#include <bits/stdc++.h>
using namespace std;

// by inforkc
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void bfs(vector<int> adj[], int v, int s)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (q.empty() == false)
    {
        int k = q.front();
        cout << k << " ";
        q.pop();
        for (auto e : adj[k])
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
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 5);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 2, 4);

    bfs(adj, v, 0);

    return 0;
}