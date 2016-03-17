/*
	���⣺ 
		
		�ҳ�����ֵ��������1.������ֵΪ��0��2.˳��ǵݼ���3.�м����Ҽ���

	˼·��

			������
			A+B+C=0  (A<=B<=C)
			A = 0-B-C
			A �±����� (0,n-3)
			��AΪ�ᣬ���� A  

					���ΪB �±�i+1
					�ұ�ΪC  �±�n-1
					if  B+C < 0-A  ����A+B+C<0,˵����Ҫ�ӵ㣺��B�±�++
					if  B+C > 0-A  ����A+B+C>0,˵����Ҫ���㣺��C�±�--
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
					while ((B<C)&&(nums[B] == nums[B + 1]))B++;//ȥ�ظ�
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
					while ((B<C) && (nums[B] == nums[B + 1]))B++;//ȥ�ظ�
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