/*
	题意： 
		
		找出离目标值最近的值，条件：1.这个值是给定的数列中的三个数的和；2.离目标值最近的只有一个数

	思路：

			先排序
			A+B+C=D  (A<=B<=C)
			A = D-B-C
			A 下标属于 [0,n-3]
			以A为轴，遍历 A  

					左边为B 下标i+1
					右边为C  下标n-1
					if  D < target  说明需要加点：即B下标++  CLOSE = min(target-D,CLOSE)
					if  D > target  说明需要减点：即C下标--  CLOSE = min(D-target,CLOSE) 
					if  D = target	NICE  CLOSE = 0  return  ret

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		vector < vector<int> > v;

		if (nums.size() < 3)
			return  0;
		
		sort(nums.begin(),nums.end(),less<int>());
		int ret = 0;
		int CLOSE = INT_MAX;
		for (size_t A = 0; A < nums.size() - 2; ++A)
		{
			if ((A != 0) && (nums[A] == nums[A - 1]))
				continue;

			size_t B = A+1;
			size_t C = nums.size() - 1;
			while ((A<B)&&(B<C))
			{
			int D = nums[A] + nums[B] + nums[C];
				int temp = target - D;
				if (abs(temp) < CLOSE)
				{
					ret = D;
					CLOSE = abs(temp);
				}
				if (temp == 0)
					return ret;
				if (temp > 0)
				{
					while ((B < C) && (nums[B] == nums[B + 1]))
						B++;
					B++;
				}
				else
				{
					while ((B < C) && (nums[C] == nums[C-1]))
						C--;
					C--;
				}
			}
		}

		return ret;
	}
};

int main(int argc,char * argv[])
{
	Solution sl;
	vector<int> num = {1,1,-1,-1,3};
	int ret = sl.threeSumClosest(num,-1);

	return 0;
}