/*
	题目 ：

		给定一个串S，发现S中最长回文串你可以假设S的最大长度是1000，并且存在一个唯一的最长回文串。

	思路：

		分奇偶两种情况

		奇数：odd
			遍历字符串，以每个字符为中心扩展

		偶数：even
			遍历字符串，以两个相邻字符一样的两个字符为中心扩展

*/ 

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
	int getRadius(string &s, int loc,bool IsOdd)const
	{
		int lhs, rhs;
		if (IsOdd)
		{
			 lhs = loc-1;
			 rhs = loc+1;
		}
		else
		{
			lhs = loc - 1;
			rhs = loc;
		}
		int length = s.size();
		int cnt = 0;
		while (
				(lhs>=0)&&
				(rhs<length)&&
				(s[lhs]==s[rhs])
				)
		{
			lhs--;
			rhs++;
			cnt++;
		}
		return cnt;
	}
	string longestPalindrome(string s) {
	
		if (s.size() <= 2)
			return s;
		//奇数 odd
		size_t odd_count = 0;
		size_t odd_pos = 0;

		for (size_t i = 0; i < s.size(); ++i)
		{
			int r = getRadius(s,i,true);
			if (odd_count < (r * 2 + 1))
			{
				odd_count = r * 2 + 1;
				odd_pos = i - r;
			}
		}//for

		//偶数 even
		size_t even_count = 0;
		size_t even_pos = 0;
		
		for (size_t i = 1; i < s.size(); ++i)
		{
			if (s[i - 1] == s[i])
			{
				int r = getRadius(s,i,false);
				if (even_count < r * 2)
				{
					even_count = 2 * r;
					even_pos = i - r;
				}
			}
		}//for

		string sub_str;
		odd_count>even_count ? sub_str = s.substr(odd_pos, odd_count) : sub_str = s.substr(even_pos, even_count);

		return sub_str;
	}
};

int main()
{
	Solution sl;
	string s("ccc");
	string result = sl.longestPalindrome(s);
	cout << result << endl;

	system("pause");
	return 0;
}