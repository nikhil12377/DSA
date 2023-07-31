// https://leetcode.com/problems/is-graph-bipartite
#include <bits/stdc++.h>
using namespace std;

bool checkColor(int start, vector<vector<int>> &graph, vector<int> &visited)
{
    int n = graph.size();
    queue<int> qt;
    qt.push(start);
    visited[start] = 0;

    while (!qt.empty())
    {
        int node = qt.front();
        qt.pop();
        for (int &i : graph[node])
        {
            if (visited[i] == -1)
            {
                int parentColor = visited[node];
                visited[i] = (parentColor == 1 ? 0 : 1);
                qt.push(i);
            }
            else if (visited[i] == visited[node])
                return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> visited(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == -1)
        {
            if (!checkColor(i, graph, visited))
                return false;
        }
    }

    return true;
}