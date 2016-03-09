/*
		题意：

			vector中的元素是该点的高度，任意两点间的下标差是举例，任意两个点可连接成举行，
			找出矩形面积最大的两个点，并返回面积。

		思路：

			距离由远到近，高度低的移动，面积最大的一定含在其中。

	
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
