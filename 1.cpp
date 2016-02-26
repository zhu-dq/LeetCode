/*
	Two Sum

题意 : 给定一个数组，和一个目标值，在数组中找到两值相加等于目标值（唯一解），返回这两个值的下标。

Example :

	Given nums = [2, 7, 11, 15], target = 9,
	Because nums[0] + nums[1] = 2 + 7 = 9,
	return [0, 1].

思路 ：

	要返回的是下标，即下标应该为值，数组值为key。即容器应该选map。如果数据只需要访问不需要顺序，就可以选择哈希表。
	map（红黑树）、unordered_map(哈希表 ：查询O(1)，c++11) 

	化二为一

	A + B = target
	B = target - A

	如果能在hash_mp中找到（target - A）；就已经找到了A、B及其下标。

	方法一、两次遍历。

	第一次初始化 hash_mp
	第二次 逐个遍历 hash_mp中的每个元素A，find（target - A），存在即找到

	方法二、一次遍历

	即 将 第一次 和 第二次合并。
	即 每当为hash_mp添加一个A元素的时候就对hash_mp做一次find(target - A)

	疑问：这时候hash_mp还没有建完成。如果你现在find(target - A) 会不会这个（target - A）在后面还没有加进来呢？
			即会不会存在考虑不周全的地方？
			|*|*|*|A||||||(target - A)||||||||||
	答 ： 不会。利用 A 与 (target - A)的对称性
			|*|*|*|(target - A)||||||A||||||||||。因为你现在遗漏的情况会在后面补上。


	总结：核心三点：
	1.化二为一 
	2.利用对称性
	3.利用hash 空间换时间

*/

#include <iostream>
#include <unordered_map> //哈希
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> result;
		//  1. 建立 一个 hash map
		unordered_map<int,int> hash_mp;
		

		/*
			2. 为这个hash map  赋值 && find  (target - A)

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