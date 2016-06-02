/*
	题目：26. Remove Duplicates from Sorted Array
	题解：
		有序vector去重
		利用set容器，天然去重
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		set<int> s(nums.begin(),nums.end());
		nums.assign(s.begin(),s.end());
		return nums.size();
	}
};