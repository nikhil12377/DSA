// https://leetcode.com/problems/course-schedule/
#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> inDegree(numCourses);
    vector<int> adj[numCourses];
    for (auto &nodes : prerequisites)
    {
        int node = nodes[1];
        adj[nodes[0]].push_back(node);
        inDegree[node]++;
    }

    queue<int> qt;
    for (int i = 0; i < numCourses; i++)
    {
        if (inDegree[i] == 0)
            qt.push(i);
    }

    int ct = 0;
    while (!qt.empty())
    {
        int node = qt.front();
        qt.pop();
        ct++;
        for (int &i : adj[node])
        {
            inDegree[i]--;
            if (inDegree[i] == 0)
                qt.push(i);
        }
    }

    return ct == numCourses;
}