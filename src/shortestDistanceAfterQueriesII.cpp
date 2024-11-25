/**
 * 3244. 新增道路查询后的最短距离 II
给你一个整数 n 和一个二维整数数组 queries。

有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。

queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1 的最短路径的长度。

所有查询中不会存在两个查询都满足 queries[i][0] < queries[j][0] < queries[i][1] < queries[j][1]。

返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric> // for iota

using namespace std;

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
{
    vector<int> roads(n);
    iota(roads.begin(), roads.end(), 1); // Initialize roads to {1, 2, 3, ..., n}
    vector<int> res;
    int dist = n - 1;

    for (auto &query : queries)
    {
        int k = roads[query[0]];
        roads[query[0]] = query[1];
        while (k != -1 && k < query[1])
        {
            int t = roads[k];
            roads[k] = -1;
            k = t;
            dist--;
        }
        res.push_back(dist);
    }

    return res;
}

vector<int> shortestDistanceAfterQueriesI(int n, vector<vector<int>> &queries)
{
    vector<int> result;
    vector<vector<int>> roads(n, vector<int>(n, INT_MAX));

    // Initialize the roads matrix
    for (int i = 0; i < n; i++)
    {
        roads[i][i] = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        roads[i][i + 1] = 1;
    }

    // Precompute shortest paths using Floyd-Warshall algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (roads[i][k] != INT_MAX && roads[k][j] != INT_MAX)
                {
                    roads[i][j] = min(roads[i][j], roads[i][k] + roads[k][j]);
                }
            }
        }
    }

    // Process each query
    for (const auto &query : queries)
    {
        int u = query[0], v = query[1];
        roads[u][v] = 1;

        // Update shortest paths with the new road
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (roads[i][k] != INT_MAX && roads[k][j] != INT_MAX)
                    {
                        roads[i][j] = min(roads[i][j], roads[i][k] + roads[k][j]);
                    }
                }
            }
        }

        int shortest = roads[0][n - 1];
        result.push_back(shortest == INT_MAX ? -1 : shortest);
    }

    return result;
}

vector<int> shortestDistanceAfterQueriesII(int n, vector<vector<int>> &queries)
{
    vector<int> result;
    vector<vector<int>> roads(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n - 1; i++)
    {
        roads[i][i + 1] = 1;
    }

    int shortest = n - 1;
    for (const auto &query : queries)
    {
        int u = query[0], v = query[1];
        roads[u][v] = 1;
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (roads[i][k] != INT_MAX && roads[k][j] != INT_MAX)
                    {
                        roads[i][j] = min(roads[i][j], roads[i][k] + roads[k][j]);
                    }
                }
            }
        }
        shortest = roads[0][n - 1];
        result.push_back(shortest == INT_MAX ? -1 : shortest);
    }

    return result;
}

int main()
{
    int n = 650;
    vector<vector<int>> queries = {{538, 577}, {438, 588}, {596, 633}, {629, 633}};

    vector<int> result = shortestDistanceAfterQueriesII(n, queries);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}