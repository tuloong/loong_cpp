/***
 *
 * 给你一个整数 n 和一个二维整数数组 queries。

有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。

queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1 的最短路径的长度。

返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <limits>

using namespace std;

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
{
    // 定义图的数据结构，使用邻接表表示
    vector<vector<pair<int, int>>> graph(n);
    // 初始化图，构建一条从节点 i 到节点 i+1 的边，权重为 1
    for (int i = 0; i < n - 1; ++i)
    {
        graph[i].push_back({i + 1, 1});
    }

    // 存储每个查询的结果
    vector<int> answer;
    // 遍历每个查询
    for (const auto &query : queries)
    {
        // 获取查询中的两个节点
        int ui = query[0], vi = query[1];
        // 在图中添加一条从 ui 到 vi 的边，权重为 1
        graph[ui].emplace_back(vi, 1);

        // 初始化距离数组，所有节点的距离初始值为最大整数
        vector<int> dist(n, numeric_limits<int>::max());
        // 起始节点的距离为 0
        dist[0] = 0;

        // 使用优先队列实现 Dijkstra 算法
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // 将起始节点加入优先队列
        pq.emplace(0, 0);

        // 当优先队列不为空时继续处理
        while (!pq.empty())
        {
            // 取出当前距离最小的节点
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // 如果当前距离大于已记录的距离，则跳过
            if (d > dist[u])
                continue;

            // 遍历当前节点的所有邻居
            for (const auto &[v, w] : graph[u])
            {
                // 如果通过当前节点到达邻居节点的距离更短，则更新距离并加入优先队列
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        // 将最后一个节点的距离加入结果数组
        answer.push_back(dist[n - 1]);
    }
    // 返回所有查询的结果
    return answer;
}

int main()
{
    int n = 5;
    vector<vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
    vector<int> res = shortestDistanceAfterQueries(n, queries);
    for (auto i : res)
    {
        cout << i << "\n"
             << " ";
    }
    return 0;
}