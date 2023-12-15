// Kahn's algorithm for topological sorting using bfs
#include <bits/stdc++.h>
using namespace std;

// by inforkc
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
void topo(vector<int> adj[], int v, int ind[])
{
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto i : adj[u])
        {
            ind[i]--;
            if (ind[i] == 0)
            {
                q.push(i);
            }
        }
    }
}
void topoSort(vector<int> adj[], int v)
{
    // code here
    int ind[v] = {0};
    for (int i = 0; i < v; i++)
    {
        for (auto a : adj[i])
        {
            ind[a]++;
        }
    }
    vector<int> arr;
    topo(adj, v, ind);
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
    topoSort(adj, v);
    return 0;
}