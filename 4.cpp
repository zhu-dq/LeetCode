/*
	����:
	
		�ҵ������������������λ����Ҫ��ʱ�临�Ӷ� O(log(m+n))

	˼·��
		
		������֮������������ż��
		������(m+n)/2 +1
		ż����(m+n)/2
		����mid = ((m+n)+(m+n)%2)  / 2

		����������
		1. �ҵ� midλ�� ������Ԫ�رȽ� i++ �� j++ �ҵ�midλ�ã�
		2. �ٽ����� ������Ϊ�����  �ҵ�midʱ������������û�е�ͷ��

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		/*
			�п�
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
			�� mid
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

		if ((m + n) % 2)//����ż
		{
			result = flag ? nums1[i-1] : nums2[j-1];
		}
		else
		{
			if (flag)//���ĸ�����
			{
				if (i == m)//1�����Ƿ�ͷ
					result = (nums1[i - 1] + nums2[j]) / 2.0;
				else if (j==n)//2�����Ƿ�ͷ
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