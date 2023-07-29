// https://leetcode.com/problems/surrounded-regions
#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &visited)
{
    visited[row][col] = 1;
    int n = board.size();
    int m = board[0].size();
    int delrows[4] = {+1, 0, -1, 0};
    int delcols[4] = {0, +1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrows[i];
        int ncol = col + delcols[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && (!visited[nrow][ncol]) && (board[nrow][ncol] == '0'))
            dfs(nrow, ncol, board, visited);
    }
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        if (!visited[0][j] && board[0][j] == 'O')
            dfs(0, j, board, visited);
        if (!visited[n - 1][j] && board[n - 1][j] == 'O')
            dfs(n - 1, j, board, visited);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i][0] && board[i][0] == 'O')
            dfs(i, 0, board, visited);
        if (!visited[i][m - 1] && board[i][m - 1] == 'O')
            dfs(i, m - 1, board, visited);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
                board[i][j] = 'X';
        }
    }
}
