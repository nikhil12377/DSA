// https://leetcode.com/problems/number-of-provinces
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &isConnected, vector<int> &visited, int node)
{
    visited[node] = 1;
    int index = 1;
    for (int i = 1; i < isConnected[node].size(); i++)
    {
        if (!visited[i] && isConnected[node][i])
            dfs(isConnected, visited, i);
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int ans = 0;
    int n = isConnected.size();
    int m = isConnected[0].size();
    vector<int> visited(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[j] && isConnected[i][j])
            {
                ans++;
                dfs(isConnected, visited, j);
            }
        }
    }

    return ans;
}