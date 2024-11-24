/**
 *
 632. 最小区间
困难
相关标签
相关企业
你有 k 个 非递减排列 的整数列表。找到一个 最小 区间，使得 k 个列表中的每个列表至少有一个数包含在其中。

我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
vector<int> smallestRange(vector<vector<int>> &nums)
{
    vector<pair<int, int>> ordered; // (number, group)
    for (size_t k = 0; k < nums.size(); ++k)
        for (auto n : nums[k])
            ordered.push_back({n, k});
    sort(ordered.begin(), ordered.end());

    int i = 0, k = 0;
    vector<int> ans;
    unordered_map<int, int> count;
    for (size_t j = 0; j < ordered.size(); ++j)
    {
        if (!count[ordered[j].second]++)
            ++k;
        if (k == nums.size())
        {
            while (count[ordered[i].second] > 1)
                --count[ordered[i++].second]; // minialize range
            if (ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first)
            {
                ans = vector<int>{ordered[i].first, ordered[j].first};
            }
        }
    }

    return ans;
}
