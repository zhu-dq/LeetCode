/*
	��Ŀ ��

		����һ����S������S������Ĵ�����Լ���S����󳤶���1000�����Ҵ���һ��Ψһ������Ĵ���

	˼·��

		����ż�������

		������odd
			�����ַ�������ÿ���ַ�Ϊ������չ

		ż����even
			�����ַ����������������ַ�һ���������ַ�Ϊ������չ

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
		//���� odd
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

		//ż�� even
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