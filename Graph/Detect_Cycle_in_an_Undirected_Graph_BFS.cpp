// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;

bool findCycle(int src, vector<int> adj[], vector<int> &visited)
{
    struct graph
    {
        int node;
        int parent;
    };

    visited[src] = 1;
    queue<graph> qt;
    qt.push({src, -1});

    while (!qt.empty())
    {
        graph temp = qt.front();
        int node = temp.node;
        int parent = temp.parent;
        qt.pop();
        for (int &i : adj[node])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                qt.push({i, node});
            }
            else if (parent != i)
                return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> visited(V + 1, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            if (findCycle(i, adj, visited))
                return true;
    }

    return false;
}