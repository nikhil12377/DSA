// https://leetcode.com/problems/01-matrix
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int delrows[4] = {+1, 0, -1, 0};
    int delcols[4] = {0, +1, 0, -1};
    queue<pair<int, int>> qt;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
                qt.push({i, j});
        }
    }

    int level = 0;
    while (!qt.empty())
    {
        level++;
        int size = qt.size();
        for (int i = 0; i < size; i++)
        {
            int currow = qt.front().first;
            int curcol = qt.front().second;
            qt.pop();
            if (mat[currow][curcol] != 0)
                ans[currow][curcol] = level;
            for (int index = 0; index < 4; index++)
            {
                int nrow = currow + delrows[i];
                int ncol = curcol + delcols[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1 && (!visited[nrow][ncol]))
                {
                    visited[nrow][ncol] = 1;
                    qt.push({nrow, ncol});
                }
            }
        }
    }

    return ans;
}