// https://leetcode.com/problems/number-of-enclaves
#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<int> &delrows, vector<int> &delcols)
{
    visited[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrows[i];
        int ncol = col + delcols[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && (!visited[nrow][ncol]) && (grid[nrow][ncol] == 1))
            dfs(nrow, ncol, grid, visited, delrows, delcols);
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<int> delrows = {+1, 0, -1, 0};
    vector<int> delcols = {0, +1, 0, -1};

    for (int i = 0; i < n; i++)
    {
        if (!visited[i][0] && grid[i][0] == 1)
            dfs(i, 0, grid, visited, delrows, delcols);
        if (!visited[i][m - 1] && grid[i][m - 1] == 1)
            dfs(i, m - 1, grid, visited, delrows, delcols);
    }

    for (int j = 0; j < m; j++)
    {
        if (!visited[0][j] && grid[0][j] == 1)
            dfs(0, j, grid, visited, delrows, delcols);
        if (!visited[n - 1][j] && grid[n - 1][j] == 1)
            dfs(n - 1, j, grid, visited, delrows, delcols);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
                ans++;
        }
    }

    return ans;
}
