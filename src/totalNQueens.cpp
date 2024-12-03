/*
52. N 皇后 II
困难
n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。

示例 1：
https://assets.leetcode.com/uploads/2020/11/13/queens.jpg
输入：n = 4
输出：2
解释：如上图所示，4 皇后问题存在两个不同的解法。

示例 2：

输入：n = 1
输出：1


提示：

1 <= n <= 9
*/

#include <iostream>
#include <vector>

using namespace std;

// 递归函数，尝试在棋盘的第k行放置皇后
// 参数：
// k: 当前处理的行号
// cols: 记录哪些列已经放置了皇后，使用位掩码表示
// diagonals1: 记录哪些对角线（左上到右下）已经放置了皇后，使用位掩码表示
// diagonals2: 记录哪些对角线（右上到左下）已经放置了皇后，使用位掩码表示
// count: 解的计数器，每找到一个有效布局就加一
// n: 棋盘的大小，即N皇后问题的N
void placeQueens(int k, int cols, int diagonals1, int diagonals2, int &count, int n)
{
    // 如果所有行都已放置了皇后，表示找到一个有效布局
    if (k == n)
    {
        count++;
        return;
    }

    // 遍历当前行的所有列
    for (int j = 0; j < n; j++)
    {
        // 计算当前列的位掩码
        int col_mask = 1 << j;
        // 计算当前对角线1的位掩码（左上到右下）
        int diag1_mask = 1 << (k - j + n - 1);
        // 计算当前对角线2的位掩码（右上到左下）
        int diag2_mask = 1 << (k + j);

        // 检查当前列和对角线是否已有皇后
        if ((cols & col_mask) == 0 &&
            (diagonals1 & diag1_mask) == 0 &&
            (diagonals2 & diag2_mask) == 0)
        {
            // 如果当前位置安全，递归尝试下一行
            // 更新cols, diagonals1, diagonals2以标记当前位置已放置皇后
            placeQueens(k + 1, cols | col_mask, diagonals1 | diag1_mask, diagonals2 | diag2_mask, count, n);
        }
    }
}

int totalNQueens(int n)
{
    if (n < 1)
        return 0;
    int count = 0;
    placeQueens(0, 0, 0, 0, count, n);
    return count;
}