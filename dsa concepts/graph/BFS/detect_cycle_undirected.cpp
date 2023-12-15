// detect cycle in undirected graph using bfs
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool detect_cycle_undirected(vector<int> adj[], int v, int s, int parent[])
{
    bool visited[v] = {0};
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
                q.push(i);
                parent[i] = u;
            }
            else if (i != parent[u])
                return true;
        }
    }
    return false;
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
    bool k;
    int parent[v] = {-1};
    for (int i = 0; i < e; i++)
    {
        k = detect_cycle_undirected(adj, v, i, parent);
        if (k)
            break;
    }
    if (k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
