// detect cycle in undirected graph using dfs
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool dfsRec(vector<int> adj[], bool visited[], int s, int parent)
{
    visited[s] = true;
    for (auto i : adj[s])
    {
        if (!visited[i])
        {
            if (dfsRec(adj, visited, i, s))
                return true;
        }
        else if (i != parent)
            return true;
    }
    return false;
}
bool detect_dfs(vector<int> adj[], int v)
{
    bool visited[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (dfsRec(adj, visited, i, -1))
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

    if (detect_dfs(adj, v))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
