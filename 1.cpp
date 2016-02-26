/*
	Two Sum

���� : ����һ�����飬��һ��Ŀ��ֵ�����������ҵ���ֵ��ӵ���Ŀ��ֵ��Ψһ�⣩������������ֵ���±ꡣ

Example :

	Given nums = [2, 7, 11, 15], target = 9,
	Because nums[0] + nums[1] = 2 + 7 = 9,
	return [0, 1].

˼· ��

	Ҫ���ص����±꣬���±�Ӧ��Ϊֵ������ֵΪkey��������Ӧ��ѡmap���������ֻ��Ҫ���ʲ���Ҫ˳�򣬾Ϳ���ѡ���ϣ��
	map�����������unordered_map(��ϣ�� ����ѯO(1)��c++11) 

	����Ϊһ

	A + B = target
	B = target - A

	�������hash_mp���ҵ���target - A�������Ѿ��ҵ���A��B�����±ꡣ

	����һ�����α�����

	��һ�γ�ʼ�� hash_mp
	�ڶ��� ������� hash_mp�е�ÿ��Ԫ��A��find��target - A�������ڼ��ҵ�

	��������һ�α���

	�� �� ��һ�� �� �ڶ��κϲ���
	�� ÿ��Ϊhash_mp���һ��AԪ�ص�ʱ��Ͷ�hash_mp��һ��find(target - A)

	���ʣ���ʱ��hash_mp��û�н���ɡ����������find(target - A) �᲻�������target - A���ں��滹û�мӽ����أ�
			���᲻����ڿ��ǲ���ȫ�ĵط���
			|*|*|*|A||||||(target - A)||||||||||
	�� �� ���ᡣ���� A �� (target - A)�ĶԳ���
			|*|*|*|(target - A)||||||A||||||||||����Ϊ��������©��������ں��油�ϡ�


	�ܽ᣺�������㣺
	1.����Ϊһ 
	2.���öԳ���
	3.����hash �ռ任ʱ��

*/

#include <iostream>
#include <unordered_map> //��ϣ
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> result;
		//  1. ���� һ�� hash map
		unordered_map<int,int> hash_mp;
		

		/*
			2. Ϊ���hash map  ��ֵ && find  (target - A)

		*/
		for (unsigned int i = 0; i < nums.size(); ++i)
		{
			if (hash_mp.count(target - nums[i]))
			{
				result.push_back(i);
				result.push_back(hash_mp[target - nums[i]]);
			}
			hash_mp[nums[i]] = i;
		}
		return result;
	}
};

int main(int argc,char* argv[])
{
	vector<int> nums = {2,3,7,5};
	int target = 12;
	Solution sl;
	vector<int> res = sl.twoSum(nums,target);

	for (auto & elem : res)
		cout << elem << endl;

	system("pause");

	return 0;
}