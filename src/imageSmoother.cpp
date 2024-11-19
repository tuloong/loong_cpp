/*
图像平滑器 是大小为 3 x 3 的过滤器，用于对图像的每个单元格平滑处理，平滑处理后单元格的值为该单元格的平均灰度。

每个单元格的  平均灰度 定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。

如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4 个单元格的平均值）。1

给你一个表示图像灰度的 m x n 整数矩阵 img ，返回对图像的每个单元格平滑处理后的图像 。

m == img.length
n == img[i].length
1 <= m, n <= 200
0 <= img[i][j] <= 255
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>> &img)
{
    int m = img.size();
    int n = img[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int sum = 0;
            int count = 0;
            for (int x = i - 1; x <= i + 1; ++x)
            {
                for (int y = j - 1; y <= j + 1; ++y)
                {
                    if (x >= 0 && x < m && y >= 0 && y < n)
                    {
                        sum += img[x][y];
                        ++count;
                    }
                }
            }

            // 向下取整
            res[i][j] = sum / count;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> img1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    return 0;
}