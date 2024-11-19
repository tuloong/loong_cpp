/***
 * 给你一个 m x n 的二进制矩阵 grid 。

如果矩阵中一行或者一列从前往后与从后往前读是一样的，那么我们称这一行或者这一列是 回文 的。

你可以将 grid 中任意格子的值 翻转 ，也就是将格子里的值从 0 变成 1 ，或者从 1 变成 0 。

请你返回 最少 翻转次数，使得矩阵 要么 所有行是 回文的 ，要么所有列是 回文的 。
 * ***/

#include <vector>
#include <functional>
#include <iostream>

using namespace std;

int minFlips(vector<vector<int>> &grid)
{
    int col = grid.size();
    int row = grid[0].size();
    int resCol = 0;
    int resRow = 0;
    int midRow = row / 2;
    int midCol = col / 2;

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (j == midRow)
            {
                break;
            }
            int a = grid[i][j];
            int b = grid[i][row - j - 1];
            if (a != b)
            {
                resRow++;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j == midCol)
            {
                break;
            }
            
            int a = grid[j][i];
            int b = grid[col - j - 1][i];
            if (a != b)
            {
                resCol++;
            }
        }
    }

    return min(resRow, resCol);
}

int main()
{
    // vector<vector<int>> gridCase1 = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    // cout << "gridCase1: " << minFlips(gridCase1) << endl;

    vector<vector<int>> gridCase2 = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    cout << "gridCase2: " << minFlips(gridCase2) << endl;

    vector<vector<int>> gridCase2 = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    cout << "gridCase2: " << minFlips(gridCase2) << endl;

    // 停顿等待输入，方便调试
    cin.get();
    return 0;
}