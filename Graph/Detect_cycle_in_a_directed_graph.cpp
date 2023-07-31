// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited)
{
    visited[node] = 1;
    pathVisited[node] = 1;
    for (int &i : adj[node])
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, pathVisited))
                return true;
        }
        else if (pathVisited[i])
            return true;
    }

    pathVisited[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, pathVisited))
                return true;
        }
    }

    return false;
}