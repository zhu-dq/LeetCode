/*
 *
 * 题目：给定n个整数和一个target数字，返回所有可能的子集:a+b+c+d=target
 * 要求：
 *       1.在一个子集的元素必须在非降序排列:a<=b<=c<=d
 *       2.该解决方案集必须不包含重复的子集
 * 思路：
 *      1 . 将a b c d  分为 A(a+b) B(c+d)
 *      2 . 将所有 nums[i] + nums[j] 二值和做hash存储
 *      3 . 遍历所有 A  从hashtable找 target -A
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using  namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        if(nums.size()<4)
            return result;

        //1 .  排序  a <= b <= c <= d
        sort(nums.begin(),nums.end());

        //2 .  将c+d的值B hash存储
        unordered_map<int,vector<pair<int,int>>> m2map;
        for(int i =0;i<nums.size()-1;++i)
            for(int j = i+1;j<nums.size();++j)
            {
                int B = nums[i]+nums[j];
                m2map[B].push_back(pair<int,int>(i,j));
            }

        for(int i =0;i<nums.size()-1;++i)
            for(int j = i+1;j<nums.size();++j)
            {
                int A = nums[i]+nums[j];
                int B = target-A;

                //3 . 找到，符合条件的话就存储
                if(m2map.count(B))
                {
                    for(auto & item : m2map[B])
                    {
                        if(item.first<=j)
                            continue;
                        int a = nums[i];
                        int b = nums[j];
                        int c = nums[item.first];
                        int d = nums[item.second];

                        //vector v = {a,b,c,d};
                        result.push_back({a,b,c,d});
                    }
                }
            }

        // 4 .  vector 去重标准套路

        sort(result.begin(),result.end());// （1）
        //vector<vector<int>>::iterator iter = unique(result.begin(),result.end());
        const auto & iter = unique(result.begin(),result.end());
        result.erase(iter,result.end());
        return result;
    }
};