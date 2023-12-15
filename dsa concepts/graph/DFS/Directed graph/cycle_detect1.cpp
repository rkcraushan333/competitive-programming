#include <bits/stdc++.h>
using namespace std;

// by inforkc
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
bool dfsRec(vector<int> adj[], int s, bool visited[], bool rstack[])
{
    visited[s] = 1;
    rstack[s] = true;
    for (auto i : adj[s])
    {
        if (visited[i] == false)
        {
            if (dfsRec(adj, i, visited, rstack))
                return true;
        }
        else if (rstack[i] == true)
            return true;
    }
    rstack[s] = false;
    return false;
}
bool cycle(vector<int> adj[], int v)
{
    bool visited[v] = {0};
    bool rstack[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (dfsRec(adj, i, visited, rstack))
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
    if (cycle(adj, v))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}