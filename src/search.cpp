/***
 *
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 */

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    if (nums.size() == 1 && nums[0] == target)
    {
        return 0;
    }
    else if (nums.size() == 1 && nums[0] != target)
    {
        return -1;
    }

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> nums = {9, 10};
    int target = 5;
    int result = search(nums, target);
    cout << result << endl;
    return 0;
}
