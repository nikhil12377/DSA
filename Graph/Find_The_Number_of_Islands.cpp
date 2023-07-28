// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int _row, int _col)
{
    visited[_row][_col] = 1;
    queue<pair<int, int>> qt;
    qt.push({_row, _col});
    int n = grid.size();
    int m = grid[0].size();

    while (!qt.empty())
    {
        int row = qt.front().first;
        int col = qt.front().second;
        qt.pop();
        for (int deltarow = -1; deltarow <= 1; deltarow++)
        {
            for (int deltacol = -1; deltacol <= 1; deltacol++)
            {
                int currow = row + deltarow;
                int curcol = col + deltacol;
                if ((currow >= 0 && currow < n) && (curcol >= 0 && curcol < m) && (grid[currow][curcol] == '1') && (!visited[currow][curcol]))
                {
                    visited[currow][curcol] = 1;
                    qt.push({currow, curcol});
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int ct = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!visited[row][col] && grid[row][col] == '1')
            {
                bfs(grid, visited, row, col);
                ct++;
            }
        }
    }

    return ct;
}