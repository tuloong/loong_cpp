/*

3232. 判断是否可以赢得数字游戏
简单
给你一个 正整数 数组 nums。

Alice 和 Bob 正在玩游戏。在游戏中，Alice 可以从 nums 中选择所有个位数 或 所有两位数，剩余的数字归 Bob 所有。如果 Alice 所选数字之和 严格大于 Bob 的数字之和，则 Alice 获胜。

如果 Alice 能赢得这场游戏，返回 true；否则，返回 false。
*/

#include <iostream>
#include <vector>

using namespace std;

bool canAliceWin(vector<int> &nums)
{
    int sumSingleDigit = 0;
    int sumDoubleDigit = 0;
    int sumOthers = 0;

    for (int num : nums)
    {
        if (num >= 1 && num <= 9)
        {
            sumSingleDigit += num;
        }
        else if (num >= 10 && num <= 99)
        {
            sumDoubleDigit += num;
        }
        else
        {
            sumOthers += num;
        }
    }

    // Calculate the remaining sum for Bob in both cases
    int sumBobSingle = sumOthers + sumDoubleDigit;
    int sumBobDouble = sumOthers + sumSingleDigit;

    // Alice wins if her sum is strictly greater than Bob's sum in either case
    return sumSingleDigit > sumBobSingle || sumDoubleDigit > sumBobDouble;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 10};
    cout << (canAliceWin(nums) ? "true" : "false") << endl; // true

    return 0;
}