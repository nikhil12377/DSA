// https://practice.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> adj[], vector<int> &visited, stack<int> &nodes)
{
    visited[src] = 1;
    for (int &node : adj[src])
    {
        if (!visited[node])
            dfs(node, adj, visited, nodes);
    }

    nodes.push(src);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> ans;
    stack<int> nodes;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, nodes);
        }
    }

    while (!nodes.empty())
    {
        ans.push_back(nodes.top());
        nodes.pop();
    }

    return ans;
}