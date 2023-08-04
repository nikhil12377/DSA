// https://leetcode.com/problems/find-eventual-safe-states/
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &graph, vector<int> &visited, vector<int> &pathVisited, vector<int> &check)
{
    visited[node] = 1;
    pathVisited[node] = 1;
    for (int &i : graph[node])
    {
        if (!visited[i])
        {
            if (dfs(i, graph, visited, pathVisited, check))
                return true;
        }
        else if (pathVisited[i])
            return true;
    }

    check[node] = 1;
    pathVisited[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);
    vector<int> check(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited, pathVisited, check);
        }
    }

    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (check[i])
            ans.push_back(i);
    }

    return ans;
}