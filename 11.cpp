/*
		���⣺

			vector�е�Ԫ���Ǹõ�ĸ߶ȣ������������±���Ǿ�������������������ӳɾ��У�
			�ҳ�����������������㣬�����������

		˼·��

			������Զ�������߶ȵ͵��ƶ����������һ���������С�

	
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		
		if (height.size() < 2)
			return 0;

		int maxArea = 0;
		int i = 0;
		int j = height.size() - 1;

		while (i<j)
		{
			int now_width = j - i;
			int now_high = min(height[i],height[j]);
			maxArea = max(maxArea,now_high*now_width);
			height[i]>height[j] ? j-- : i++;
		}
		return maxArea;
	}
};
