/*
	题意：

		求一个vector<string>中所有string的公共最长前缀

	思路：

		同时遍历每个string，字符不同时就可以停止了
		题目不难：注意一些小地方，比如：
		1.vector 不为空不代表里面的string没有空
		2.break的作用域是"最近的循环"
		3.各个分支都要保证正常return

*/


#include<iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.empty())
			return "";

		for (auto & elem : strs)
		{
			if (elem.empty())
				return "";
		}

		if (strs.size() == 1)
			return strs[0];

		int i = 0;
		while ( true )
		{
			if (i == strs[0].size())
				return strs[0].substr(0, i);
			char c = strs[0][i];
			for (auto & str : strs)
			{
				if (i == str.size() || c != str[i])
					return strs[0].substr(0, i);
			}
			i++;
		}
	}
};

int main(int argc,char * argv[])
{
	vector<string> v = {"abab","aba","abc"};
	Solution sl;
	string str = sl.longestCommonPrefix(v);

	return 0;
}