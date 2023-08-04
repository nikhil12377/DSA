// https://practice.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> inDegree(V, 0);
    vector<int> ans;
    queue<int> qt;

    for (int i = 0; i < V; i++)
    {
        for (int &node : adj[i])
        {
            inDegree[node]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (!inDegree[i])
            qt.push(i);
    }

    while (!qt.empty())
    {
        int temp = qt.front();
        qt.pop();
        ans.push_back(temp);
        for (int &node : adj[temp])
        {
            inDegree[node]--;
            if (!inDegree[node])
                qt.push(node);
        }
    }

    return ans;
}