/***
743. 网络延迟时间
中等
有 n 个网络节点，标记为 1 到 n。

给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。

现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。

示例 1：



输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
输出：2
示例 2：

输入：times = [[1,2,1]], n = 2, k = 1
输出：1
示例 3：

输入：times = [[1,2,1]], n = 2, k = 2
输出：-1


提示：

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
所有 (ui, vi) 对都 互不相同（即，不含重复边）
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    const int INF = INT_MAX / 2;                   // 定义一个常量，表示无穷大，初始化距离
    vector<vector<int>> g(n, vector<int>(n, INF)); // 初始化邻接矩阵
    for (const auto &t : times)                    // 遍历times，将边的权值赋值给邻接矩阵
    {
        int x = t[0] - 1, y = t[1] - 1;
        g[x][y] = t[2];
    }

    vector<int> dist(n, INF); // 初始化距离，表示从k到各个节点的距离
    dist[k - 1] = 0;          // 起始点到自己的距离为0
    vector<int> used(n);      // 标记数组，标记节点是否已经访问过
    for (int i = 0; i < n; ++i)
    {
        int x = -1; // 用于记录最小距离的节点

        for (int y = 0; y < n; ++y) // 遍历所有节点
        {
            if (!used[y] && (x == -1 || dist[y] < dist[x])) // 如果节点未访问过且距离小于最小距离
            {
                x = y; // 更新最小距离的节点
            }
        }

        used[x] = true; // 标记节点已经访问过

        for (int y = 0; y < n; ++y) // 遍历所有节点
        {
            dist[y] = min(dist[y], dist[x] + g[x][y]); // 更新最短距离
        }
    }

    int ans = *max_element(dist.begin(), dist.end()); // 返回最大距离
    return ans == INF ? -1 : ans;
}