/*
	��Ŀ��26. Remove Duplicates from Sorted Array
	��⣺
		����vectorȥ��
		����set��������Ȼȥ��
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		set<int> s(nums.begin(),nums.end());
		nums.assign(s.begin(),s.end());
		return nums.size();
	}
};