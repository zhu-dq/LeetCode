/*
 * 题目：31. Next Permutation
 * 题意： 序类的元素按序排列组合,给出当前序列的下一个排列组合（STL 有个next_permutation）
 * 题解：
 *   1.从后往前，寻找两个相邻元素，满足a<b
 *   2.从后向前，找出第一个大于a的元素c
 *   3.操作：a和c交换（STL有个迭代器交换哈市南湖iter_swap）
 *   4.操作：将b之后的元素颠倒重排。（STL有个reverse）
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2)
            return;
        auto b =prev(nums.end());
        while (b!=nums.begin())
        {
            auto a = prev(b);
            if(*a<*b)
            {
                 auto c = prev(nums.end());
                while(!(*a<*c))c=prev(c);
                iter_swap(a,c);
                reverse(b,nums.end());
                return;
            }
            b=prev(b);
        }
        reverse(nums.begin(),nums.end());
        return;
    }
};