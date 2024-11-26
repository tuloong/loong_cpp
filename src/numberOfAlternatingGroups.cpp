/*
 *
3206. 交替组 I
简单
给你一个整数数组 colors ，它表示一个由红色和蓝色瓷砖组成的环，第 i 块瓷砖的颜色为 colors[i] ：

colors[i] == 0 表示第 i 块瓷砖的颜色是 红色 。
colors[i] == 1 表示第 i 块瓷砖的颜色是 蓝色 。
环中连续 3 块瓷砖的颜色如果是 交替 颜色（也就是说中间瓷砖的颜色与它 左边 和 右边 的颜色都不同），那么它被称为一个 交替 组。

请你返回 交替 组的数目。

注意 ，由于 colors 表示一个 环 ，第一块 瓷砖和 最后一块 瓷砖是相邻的。
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numberOfAlternatingGroups(vector<int> &colors)
{
    // 在数组两端添加虚拟元素
    colors.push_back(colors[0]);
    colors.insert(colors.begin(), colors[colors.size() - 2]);

    int res = 0;

    for (int i = 1; i < colors.size() - 1; ++i)
    {
        if (colors[i] != colors[i - 1] && colors[i] != colors[i + 1])
        {
            ++res;
        }
    }

    // 移除添加的虚拟元素
    colors.erase(colors.begin());
    colors.pop_back();

    return res;
}

int main()
{
    vector<int> colors = {0, 1, 0, 0, 1};
    cout << numberOfAlternatingGroups(colors) << endl;
    return 0;
}