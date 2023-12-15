#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void shortestPath(vector<int> adj[], int v, int s)
{
    bool visited[v] = {0};
    int dis[v] = {0};
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            if (!visited[i])
            {
                visited[i] = true;
                dis[i] = dis[u] + 1;
                q.push(i);
            }
        }
    }
    for (auto i : dis)
    {
        cout << i << " ";
    }
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
    shortestPath(adj, v, 0);
}