/***

现有一棵 无向 树，树中包含 n 个节点，按从 0 到 n - 1 标记。树的根节点是节点 0 。给你一个长度为 n - 1 的二维整数数组 edges，其中 edges[i] = [ai, bi] 表示树中节点 ai 与节点 bi 之间存在一条边。

如果一个节点的所有子节点为根的
子树
 包含的节点数相同，则认为该节点是一个 好节点。

返回给定树中 好节点 的数量。

子树 指的是一个节点以及它所有后代节点构成的一棵树。
****/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/**
 * @brief Counts the number of "good" nodes in a tree.
 *
 * A "good" node is defined based on a specific criteria which is not provided in the current context.
 * This function constructs a tree from the given edges and initializes the count of good nodes.
 *
 * @param edges A vector of vectors where each inner vector represents an edge between two nodes in the tree.
 *              Each edge is represented as a pair of integers [u, v] where u and v are node indices.
 * @return int The count of good nodes in the tree.
 */
int countGoodNodes(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;
    vector<vector<int>> tree(n);
    int res = 0;

    for (const auto &edge : edges)
    {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }

    function<int(int, int)> dfs = [&](int node, int parent) -> int
    {
        bool valid = true;
        int size = 0;
        int subTreeSize = 0;
        int treeSize = 0;

        for (int child : tree[node])
        {
            if (child == parent)
            {
                continue;
            }

            size = dfs(child, node);

            if (subTreeSize == 0)
            {
                subTreeSize = size;
            }
            else if (size != subTreeSize)
            {
                valid = false;
            }

            treeSize += size;
        }

        if (valid)
        {
            res++;
        }

        return treeSize + 1;
    };

    dfs(0, -1);
    return res;
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    cout << countGoodNodes(edges) << endl;
    return 0;
}