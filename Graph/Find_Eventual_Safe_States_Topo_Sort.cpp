// https://leetcode.com/problems/find-eventual-safe-states/
#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> adjRev[V];
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int &adj : graph[i])
        {
            adjRev[adj].push_back(i);
            inDegree[i]++;
        }
    }

    queue<int> qt;
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
            qt.push(i);
    }

    vector<int> ans;

    while (!qt.empty())
    {
        int node = qt.front();
        qt.pop();
        ans.push_back(node);
        for (int &i : adjRev[node])
        {
            inDegree[i]--;
            if (inDegree[i] == 0)
                qt.push(i);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}