/*

代码
测试用例
测试结果
测试结果
9. 回文数
简单
相关标签
相关企业
提示
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数
是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。
*/

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }

    long long num = x;
    long long reverse = 0;
    while (x)
    {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }

    return x == reverse;
}