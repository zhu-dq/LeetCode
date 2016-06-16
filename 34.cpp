/*
	题目：34. Search for a Range
	题解：
		 二分查找 :  target ， pos_mid
		 循环：
			 二分查找 左 (light,pos_mid)
			 二分查找 右 (pos_mid,right)
*/
#include <iostream>
#include <vector>
using namespace std;

#define RESULT pair<int,pair<int,int>>

class Solution {
public:

	RESULT findTarget(int begin_pos, int end_pos, vector<int> & nums, int target)
	{
		if (begin_pos > end_pos)
			return RESULT(-1, pair<int, int>(-1, -1));
		int mid_pos = (begin_pos + end_pos) / 2;
		if (nums[mid_pos] == target)
			return RESULT(mid_pos, pair<int, int>(begin_pos, end_pos));
		if (begin_pos == end_pos)
			return RESULT(-1, pair<int, int>(-1, -1));
		if (nums[mid_pos]<target)
			return findTarget(mid_pos+1, end_pos, nums, target);
		return findTarget(begin_pos, mid_pos-1, nums, target);
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty())
			return{ -1, -1 };
		int l_pos = -1;
		int r_pos = -1;
		int begin_pos = 0;
		int end1_pos = nums.size() - 1;
		RESULT result = findTarget(begin_pos, end1_pos, nums, target);
		if (result.first != -1)
		{
			l_pos = r_pos = result.first;
			//l
			while (true)
			{
				RESULT l_result = findTarget(begin_pos, l_pos-1, nums, target);
				if (l_result.first == -1)
					break;
				l_pos = l_result.first;
				begin_pos = l_result.second.first;
			}
			//r
			while (true)
			{
				RESULT r_result = findTarget(r_pos+1, end1_pos, nums, target);
				if (r_result.first == -1)
					break;
				r_pos = r_result.first;
				end1_pos = r_result.second.second;
			}
		}
		return{ l_pos, r_pos };
	}
};

int main()
{
	Solution sl;
	vector<int> v = {1};
	vector<int> result = sl.searchRange(v,1);
	
	system("pause");
	return 0;
}