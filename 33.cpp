
/*
	��Ŀ��33. Search in Rotated Sorted Array
	��⣺�ҵ�ָ�������±�
		�������� ֱ�� ac   ���Ծ�û���о���Ŀ��ͼ
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