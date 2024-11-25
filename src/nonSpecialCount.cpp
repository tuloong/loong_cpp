/***
 *
 *3233. 统计不是特殊数字的数字数量
给你两个 正整数 l 和 r。对于任何数字 x，x 的所有正因数（除了 x 本身）被称为 x 的 真因数。

如果一个数字恰好仅有两个 真因数，则称该数字为 特殊数字。例如：

数字 4 是 特殊数字，因为它的真因数为 1 和 2。
数字 6 不是 特殊数字，因为它的真因数为 1、2 和 3。
返回区间 [l, r] 内 不是 特殊数字 的数字数量。
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <unordered_set>

using namespace std;

int nonSpecialCount(int l, int r)
{
    int n = sqrt(r);
    vector<int> v(n + 1);
    int res = r - l + 1;
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 0)
        {
            if (i * i >= l && i * i <= r)
            {
                res--;
            }
            for (int j = i * 2; j <= n; j += i)
            {
                v[j] = 1;
            }
        }
    }
    return res;
}

int nonSpecialCountI(int l, int r)
{
    // 不是特殊数字的数字数量
    int count = 0;
    // 真因数的数量
    int factorCount = 0;

    for (int i = l; i <= r; ++i)
    {
        factorCount = 1;
        // 判断是否是特殊数字
        for (int j = 2; j <= i / 2; ++j)
        {
            if (i % j == 0)
            {
                ++factorCount;
            }

            if (factorCount > 2)
            {
                break;
            }
        }

        if (factorCount == 2)
        {
            continue;
        }

        ++count;
    }
    return count;
}

int main()
{
    // int l = 2749;
    // int r = 64224;
    int l = 1;
    int r = 1000000000;
    // 记录运行时间 ms
    clock_t start = clock();
    cout << nonSpecialCount(l, r) << endl;
    clock_t end = clock();
    cout << "run time : " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}