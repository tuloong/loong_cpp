#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

bool isPossible(int n, vector<vector<int>> &edges)
{
    vector<int> degree(n + 1, 0);
    unordered_set<string> edgeSet;

    // 构建图并统计度数
    for (const auto &edge : edges)
    {
        int u = edge[0], v = edge[1];
        degree[u]++;
        degree[v]++;
        edgeSet.insert(to_string(u) + "#" + to_string(v));
        edgeSet.insert(to_string(v) + "#" + to_string(u));
    }

    // 统计奇数度节点
    vector<int> oddDegreeNodes;
    for (int i = 1; i <= n; ++i)
    {
        if (degree[i] % 2 != 0)
        {
            oddDegreeNodes.push_back(i);
        }
    }

    int oddCount = oddDegreeNodes.size();

    // 没有奇数度节点
    if (oddCount == 0)
    {
        return true;
    }

    // 2 个奇数度节点
    if (oddCount == 2)
    {
        int u = oddDegreeNodes[0];
        int v = oddDegreeNodes[1];
        string edge = to_string(u) + "," + to_string(v);
        if (!edgeSet.count(edge))
        {
            return true;
        }
        return false;
    }

    // 4 个奇数度节点
    if (oddCount == 4)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = i + 1; j < 4; ++j)
            {
                for (int k = 0; k < 4; ++k)
                {
                    if (k == i || k == j)
                        continue;
                    for (int l = k + 1; l < 4; ++l)
                    {
                        if (l == i || l == j)
                            continue;
                        string edge1 = to_string(oddDegreeNodes[i]) + "#" + to_string(oddDegreeNodes[j]);
                        string edge3 = to_string(oddDegreeNodes[k]) + "#" + to_string(oddDegreeNodes[l]);
                        if (!edgeSet.count(edge1) && !edgeSet.count(edge3))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    return false;
}

int main()
{
    int n = 21;
    vector<vector<int>> edges = {
        {2, 19}, {16, 17}, {8, 14}, {2, 16}, {12, 20}, {12, 14}, {16, 18}, {15, 16}, {10, 21}, {3, 5}, {13, 18}, {17, 20}, {14, 17}, {9, 12}, {5, 15}, {5, 6}, {3, 7}, {2, 21}, {10, 13}, {8, 16}, {7, 18}, {4, 6}, {9, 1}, {13, 21}, {18, 20}, {7, 14}, {4, 19}, {5, 8}, {3, 11}, {11, 1}, {7, 12}, {4, 7}, {3, 16}, {13, 17}, {17, 19}, {9, 13}, {7, 19}, {10, 16}, {4, 13}, {4, 5}, {2, 15}, {12, 19}, {11, 16}, {2, 9}, {11, 17}, {17, 1}, {16, 21}, {4, 10}, {10, 14}, {14, 16}, {4, 1}, {13, 20}, {5, 20}, {4, 14}, {4, 21}, {10, 20}, {2, 14}, {8, 15}, {4, 8}, {6, 19}, {15, 1}, {19, 1}, {8, 19}, {15, 21}, {3, 12}, {11, 18}, {9, 17}, {18, 19}, {7, 21}, {3, 21}, {16, 19}, {11, 15}, {5, 1}, {8, 17}, {3, 15}, {8, 1}, {10, 19}, {3, 8}, {6, 16}, {2, 8}, {5, 18}, {11, 13}, {11, 20}, {14, 21}, {6, 20}, {4, 20}, {12, 13}, {5, 12}, {10, 11}, {9, 15}, {3, 19}, {9, 20}, {14, 18}, {21, 1}, {13, 19}, {8, 21}, {2, 13}, {3, 10}, {9, 18}, {19, 21}, {6, 7}, {3, 18}, {2, 18}, {6, 14}, {3, 17}, {5, 21}, {14, 20}, {8, 9}, {16, 1}, {3, 4}, {13, 1}, {5, 9}, {4, 15}, {17, 21}, {20, 21}, {2, 17}, {13, 14}, {11, 14}, {9, 16}, {10, 18}, {6, 15}, {6, 12}, {3, 13}, {5, 11}, {6, 1}, {12, 17}, {8, 10}, {5, 10}, {8, 18}, {4, 12}, {10, 1}, {6, 13}, {4, 18}, {7, 20}, {7, 16}, {2, 6}, {12, 21}, {4, 17}, {15, 18}, {13, 16}, {15, 20}, {7, 10}, {6, 10}, {2, 20}, {7, 15}, {18, 1}, {12, 1}, {3, 20}, {7, 1}, {14, 15}, {4, 9}, {11, 19}, {7, 9}, {5, 17}, {18, 21}, {6, 21}, {8, 11}, {6, 17}, {3, 14}, {7, 11}, {5, 7}, {7, 13}, {6, 8}, {6, 9}, {10, 12}, {5, 16}, {2, 4}, {17, 18}, {9, 11}, {12, 16}, {3, 6}, {12, 18}, {3, 9}, {11, 12}, {14, 19}, {10, 15}, {5, 13}, {8, 13}, {15, 17}, {2, 10}, {11, 21}, {20, 1}, {6, 18}, {2, 12}, {19, 20}, {6, 11}, {8, 12}, {2, 3}, {12, 15}, {2, 11}, {9, 10}, {7, 17}, {9, 19}, {13, 15}, {7, 8}, {4, 11}, {2, 5}, {5, 19}, {16, 20}, {15, 19}, {9, 14}, {14, 1}, {10, 17}, {9, 21}, {2, 7}, {8, 20}, {5, 14}, {4, 16}};

    cout << (isPossible(n, edges) ? "true" : "false") << endl;
    return 0;
}
