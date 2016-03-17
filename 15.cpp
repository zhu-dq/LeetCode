/*
	题意： 
		
		找出三个值，条件：1.这三个值为和0；2.顺序非递减；3.有几个找几个

	思路：

			先排序
			A+B+C=0  (A<=B<=C)
			A = 0-B-C
			A 下标属于 (0,n-3)
			以A为轴，遍历 A  

					左边为B 下标i+1
					右边为C  下标n-1
					if  B+C < 0-A  即：A+B+C<0,说明需要加点：即B下标++
					if  B+C > 0-A  即：A+B+C>0,说明需要减点：即C下标--
					if  B+C = 0-A	 NICE

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector < vector<int> > v;

		if (nums.size() < 3)
			return  v;
		
		sort(nums.begin(),nums.end(),less<int>());
		
		for (size_t A = 0; A < nums.size() - 2; ++A)
		{
			if (nums[A]>0)
				break;
			if ((A != 0) && (nums[A] == nums[A - 1]))
				continue;

			size_t B = A+1;
			size_t C = nums.size() - 1;

			while ((A<B)&&(B<C))
			{
				if ((nums[B] + nums[C]) < (0 - nums[A]))
				{
					while ((B<C)&&(nums[B] == nums[B + 1]))B++;//去重复
					B++;
					continue;
				}
				if ((nums[B] + nums[C]) > (0 - nums[A]))
				{
					while ((B<C)&&(nums[C] == nums[C - 1]))C--;
					C--;
					continue;
				}
				if ((nums[B] + nums[C]) == (0 - nums[A]))
				{
					v.push_back({nums[A],nums[B],nums[C]});
					while ((B<C) && (nums[B] == nums[B + 1]))B++;//去重复
					B++;
					while ((B<C) && (nums[C] == nums[C - 1]))C--;
					C--;
					continue;
				}
			}
		}

		return v;
	}
};

int main(int argc,char * argv[])
{
	Solution sl;
	vector<int> v = { 0,0,0 };
	vector<vector<int>> v1 = sl.threeSum(v);

	return 0;
}