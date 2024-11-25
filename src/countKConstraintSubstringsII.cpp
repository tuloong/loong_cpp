/***
 *
 * 给你一个 二进制 字符串 s 和一个整数 k。

另给你一个二维整数数组 queries ，其中 queries[i] = [li, ri] 。

如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：

字符串中 0 的数量最多为 k。
字符串中 1 的数量最多为 k。
返回一个整数数组 answer ，其中 answer[i] 表示 s[li..ri] 中满足 k 约束 的
子字符串
 的数量。
*/
#include <vector>
#include <iostream>

using namespace std;
vector<long long> countKConstraintSubstringsII(string s, int k, vector<vector<int>> &queries)
{
    
}

int main()
{
    string s = "0001111";
    int k = 2;
    vector<vector<int>> queries = {{0, 6}};
    vector<long long> res = countKConstraintSubstringsII(s, k, queries);
    for (auto r : res)
    {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}