
/*
	题目：33. Search in Rotated Sorted Array
	题解：找到指定数据下标
		暴力遍历 直接 ac   所以就没有研究题目意图
*/
#include <vector>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == target)
				return i;
		}
		return -1;
	}
};