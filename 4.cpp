/*
	题意:
	
		找到两个已排序数组的中位数，要求时间复杂度 O(log(m+n))

	思路：
		
		两数组之和是奇数还是偶数
		奇数：(m+n)/2 +1
		偶数：(m+n)/2
		即：mid = ((m+n)+(m+n)%2)  / 2

		核心两个：
		1. 找到 mid位置 （数组元素比较 i++ 或 j++ 找到mid位置）
		2. 临近条件 （数组为空情况  找到mid时，两个数组有没有到头）

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		/*
			判空
		*/
		if (nums1.empty() && nums2.empty())
			return 0.0;

		if (nums1.empty())
		{
			size_t mid = (nums2.size() % 2 + nums2.size()) / 2;
			if (nums2.size() % 2)
				return nums2[mid-1];
			else
			{
				return (nums2[mid-1] + nums2[mid]) / 2.0;
			}
		}

		if (nums2.empty())
		{
			size_t mid = (nums1.size() % 2 + nums1.size()) / 2;
			if (nums1.size() % 2)
				return nums1[mid-1];
			else
			{
				return (nums1[mid-1] + nums1[mid]) / 2.0;
			}
		}

		double result = 0.0;
		size_t m = nums1.size();
		size_t n = nums2.size();
		size_t  mid = ((m + n) + (m + n) % 2) / 2;
		size_t i, j, cnt;
		i = 0;
		j = 0;
		cnt = 0;
		bool flag;
		/*
			找 mid
		*/
		while (cnt<mid)
		{
			cnt++;
			if (i < m && j < n)
			{
				if (nums1[i] < nums2[j])
				{
					flag = true;
					i++;
				}
				else
				{
					flag = false;
					j++;
				}
				continue;
			}
			if (i == m)
			{
				flag = false;
				j++;
			}
			else
			{
				flag = true;
				i++;
			}
		}

		if ((m + n) % 2)//判奇偶
		{
			result = flag ? nums1[i-1] : nums2[j-1];
		}
		else
		{
			if (flag)//判哪个数组
			{
				if (i == m)//1数组是否到头
					result = (nums1[i - 1] + nums2[j]) / 2.0;
				else if (j==n)//2数组是否到头
					result = (nums1[i - 1] + nums1[i]) / 2.0;
				else
					result = (nums1[i - 1] + min(nums2[j], nums1[i])) / 2.0;
			}
			else
			{
				if (j == n)
					result = (nums2[j - 1] + nums1[i]) / 2.0;
				else if (i==m)
					result = (nums2[j - 1] + nums2[j]) / 2.0;
				else
					result = (nums2[j - 1] + min(nums1[i], nums2[j])) / 2.0;
			}
		}
		return result;
	}
};
int main()
{
	Solution s;
	vector<int> v1 = {1};
	vector<int> v2 = {2,3,4};
	double result = s.findMedianSortedArrays(v1,v2);

	cout << result << endl;
	system("pause");

	return 0;
}