/*
 *
 * 题目：给定一组不同的整数，数字，返回所有可能的子集。
 * 要求：
 *       1.在一个子集的元素必须在非降序排列
 *       2.该解决方案集必须不包含重复的子集
 * 思路：
 *         1.先对这一组元素进行非降序排列（要求1）
 *         2.因为整数都不同，所以有2^n情况;
 *           对每个元素来说要么是当前子集的情况，要么不是;
 *           即可用可用0-2^n-1的每位的二进制表示每一种子集的情况
 */
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
vector<int> getsubset(int type,vector<int> & nums)
{
    bitset<64> b(type);
    vector<int> v(b.count());
    for(int pos = 0;pos<nums.size();++pos)
    {
        if(b.test(pos))
            v.push_back(nums[pos]);
    }
    return v;
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        if(nums.empty())
            return v;
        unsigned int  max = pow(2,nums.size());
        for(unsigned int i =0;i<max;++i)
        {
            v.push_back(getsubset(i,nums));
        }
    }
};
int main()
{
    Solution sl;
    vector<int> v;
    v.push_back(0);
    vector<vector<int>> vv;
    vv = sl.subsets(v);
    return 0;
}