/*
	���⣺

		��һ��vector<string>������string�Ĺ����ǰ׺

	˼·��

		ͬʱ����ÿ��string���ַ���ͬʱ�Ϳ���ֹͣ��
		��Ŀ���ѣ�ע��һЩС�ط������磺
		1.vector ��Ϊ�ղ����������stringû�п�
		2.break����������"�����ѭ��"
		3.������֧��Ҫ��֤����return

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