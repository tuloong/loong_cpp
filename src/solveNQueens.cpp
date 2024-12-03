/*
51. N 皇后
困难
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
*/

#include <iostream>
#include <vector>

using namespace std;

// 检查当前列是否有皇后
bool isColSafe(vector<int> &board, int col)
{
    for (int i = 0; i < col; ++i)
    {
        if (board[i] == col)
        {
            return false;
        }
    }
    return true;
}

// 检查左上到右下对角线是否有皇后
bool isDiagonalSafe(vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        if (abs(board[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

void solveNQueensHelper(int n, vector<int> &queens, int row, vector<vector<string>> &result)
{
    if (row == n)
    {
        // 构建结果
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; ++i)
        {
            board[i][queens[i]] = 'Q';
        }
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col)
    {
        if (isColSafe(queens, col) && isDiagonalSafe(queens, row, col))
        {
            queens[row] = col;
            solveNQueensHelper(n, queens, row + 1, result);
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<int> queens(n, -1); // 初始化为-1表示未放置皇后
    solveNQueensHelper(n, queens, 0, result);
    return result;
}