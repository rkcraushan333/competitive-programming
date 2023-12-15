// Using topological sort
#include <bits/stdc++.h>
using namespace std;
void topo(vector<pair<int, int>> adj[], int v, int ind[], vector<int> &arr)
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
        arr.push_back(u);
        for (auto i : adj[u])
        {
            ind[i.first]--;
            if (ind[i.first] == 0)
            {
                q.push(i.first);
            }
        }
    }
}
vector<int> topoSort(int v, vector<pair<int, int>> adj[])
{
    // code here
    int ind[v] = {0};
    for (int i = 0; i < v; i++)
    {
        for (auto a : adj[i])
        {
            ind[a.first]++;
        }
    }
    vector<int> arr;
    topo(adj, v, ind, arr);
    return arr;
}
// by inforkc
void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}
void shortestPath(vector<pair<int, int>> adj[], int v, int s)
{
    int arr[v] = {INT_MAX};
    arr[s] = 0;
    vector<int> k;
    k = topoSort(v, adj);
    for (auto u : k)
    {
        for (auto i : adj[u])
        {
            arr[i.first] = min(arr[u] + i.second, arr[i.first]);
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> adj[v];
    for (int i = 0; i < v; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(adj, a, b, c);
    }

    shortestPath(adj, v, 0);
    return 0;
}