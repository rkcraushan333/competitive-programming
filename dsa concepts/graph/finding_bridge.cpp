#include <bits/stdc++.h>
using namespace std;

// by inforkc
vector<int> adj[101], in(101), low(101);
vector<bool> vis(101);
int timer;
void dfs(int node, int par)
{
    vis[node] = 1;
    low[node] = in[node] = timer++;
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        if (vis[child])
        {
            // node edge - child is a back edge
            low[node] = min(low[node], in[child]);
        }
        else
        {
            // node edge - child is a forward edge
            dfs(child, node);
            if (low[child] > in[node])
            {
                cout << node << " " << child << " is a bridge." << endl;
            }
            low[node] = min(low[node], in[child]);
        }
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    return 0;
}