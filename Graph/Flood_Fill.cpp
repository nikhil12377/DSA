// https://leetcode.com/problems/flood-fill
#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int ini, int newColor, int delRow[], int delCol[], vector<vector<int>> &image)
{
    image[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == ini && image[nrow][ncol] != newColor)
        {
            dfs(nrow, ncol, ini, newColor, delRow, delCol, image);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    int ini = image[sr][sc];
    dfs(sr, sc, ini, color, delRow, delCol, image);
    return image;
}