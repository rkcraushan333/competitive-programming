#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

// Helper function to perform BFS and generate the log order
vector<int> generateBFSOrder(int n, const vector<vector<int>> &adj)
{
    vector<int> bfsOrder;
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(1); // Bootstrap process starts from process 1
    visited[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfsOrder.push_back(node);

        // Process all children (adjacent processes)
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfsOrder;
}

// Function to check if a query is valid
bool isValidQuery(const vector<int> &query, const vector<int> &correctOrder)
{
    // Create a mapping from process number to its index in the correct order
    unordered_set<int> validOrderSet(correctOrder.begin(), correctOrder.end());
    if (validOrderSet.size() != correctOrder.size())
        return false; // Sanity check for correct order

    // Create a map to check the positions of processes in the correct order
    unordered_map<int, int> correctPosition;
    for (int i = 0; i < correctOrder.size(); ++i)
    {
        correctPosition[correctOrder[i]] = i;
    }

    // Check if the query follows the correct order of processes
    for (int i = 1; i < query.size(); ++i)
    {
        // If the query[i] should come before query[i-1] in BFS order, it's invalid
        if (correctPosition[query[i]] < correctPosition[query[i - 1]])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m, q;
    cin >> n >> m; // n = number of processes, m = number of parent-child relationships

    vector<vector<int>> adj(n + 1); // Adjacency list for graph representation of processes

    // Read the process relationships
    for (int i = 0; i < m; ++i)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from); // Since the relation is bi-directional
    }

    // Generate the correct BFS order
    vector<int> correctBFSOrder = generateBFSOrder(n, adj);

    // Read the number of queries
    cin >> q;

    // Process each query
    string result = "";
    for (int i = 0; i < q; ++i)
    {
        vector<int> queryOrder(n);
        for (int j = 0; j < n; ++j)
        {
            cin >> queryOrder[j];
        }

        // Check if this query order is valid
        if (isValidQuery(queryOrder, correctBFSOrder))
        {
            result += 'f'; // Not infected (valid order)
        }
        else
        {
            result += 't'; // Infected (invalid order)
        }
    }

    // Output the result string
    cout << result << endl;

    return 0;
}
