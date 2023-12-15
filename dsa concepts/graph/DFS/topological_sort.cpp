// Kahn's algorithm for topological sorting using bfs
#include <bits/stdc++.h>
using namespace std;

// by inforkc
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
void topodfs(vector<int> adj[], int s, bool visited[], stack<int> &st)
{
    visited[s] = true;
    for (auto i : adj[s])
    {
        if (!visited[i])
            topodfs(adj, i, visited, st);
    }
    st.push(s);
}
void topoSort(vector<int> adj[], int v)
{
    // code here
    stack<int> st;
    bool visited[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topodfs(adj, i, visited, st);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
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
    topoSort(adj, v);
    return 0;
}