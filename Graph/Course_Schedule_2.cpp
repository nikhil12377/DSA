// https://leetcode.com/problems/course-schedule-ii/
#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> inDegree(numCourses);
    vector<int> adj[numCourses];
    for (auto &nodes : prerequisites)
    {
        int node = nodes[0];
        adj[nodes[1]].push_back(node);
        inDegree[node]++;
    }

    queue<int> qt;
    for (int i = 0; i < numCourses; i++)
    {
        if (inDegree[i] == 0)
            qt.push(i);
    }

    vector<int> topo;
    while (!qt.empty())
    {
        int node = qt.front();
        qt.pop();
        topo.push_back(node);
        for (int &i : adj[node])
        {
            inDegree[i]--;
            if (inDegree[i] == 0)
                qt.push(i);
        }
    }

    if (topo.size() == numCourses)
        return topo;
    return {};
}