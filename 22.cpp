/*
	题目：
			Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

			For example, given n = 3, a solution set is:

			"((()))", "(()())", "(())()", "()(())", "()()()"
	思路：
			1. 在构造的过程中，要时刻保持【已用】 “（”个数>=“）”个数
			2. 括号匹配的开始必须以"("开始，当“（”个数="）"个数，说明前面的已经完全匹配了，当前可以当成一个新的gpth
			3. 当前一个是“（”时：
					1） 当还有“（”时，当前可“（”可“）”
					2） 当没有“（”时，剩余全是")"
			4. 当前一个是“）”时：
					1） 当“（”个数==“）”个数，当前必须是“（”
					2） 当“）”个数为0，说明构建完成
					3） 当“）”个数与“（”个数不等（即【剩余】“）”个数大于“（”），当前可“（”可“）”
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void gpth(vector<string> & all_P_TH, string current_pattern, int lth_size, int rhs_size)
	{
		switch (current_pattern[current_pattern.size() - 1])
		{
		case '(':
			if (lth_size == 0)
			{
				string temp_0(current_pattern);
				string ending(rhs_size, ')');
				all_P_TH.push_back(temp_0 + ending);
			}
			else
			{
				string temp_1(current_pattern);
				temp_1.push_back('(');
				string temp_2(current_pattern);
				temp_2.push_back(')');
				gpth(all_P_TH, temp_1, lth_size - 1, rhs_size);
				gpth(all_P_TH, temp_2, lth_size, rhs_size - 1);
			}
			break;
		case ')':
			if (rhs_size == 0)
			{
				all_P_TH.push_back(current_pattern);
			}
			else if (lth_size == rhs_size)
			{
				string temp_3(current_pattern);
				temp_3.push_back('(');
				gpth(all_P_TH, temp_3, lth_size - 1, rhs_size);
			}
			else
			{
				string temp_4(current_pattern);
				temp_4.push_back('(');
				string temp_5(current_pattern);
				temp_5.push_back(')');
				gpth(all_P_TH, temp_4, lth_size - 1, rhs_size);
				gpth(all_P_TH, temp_5, lth_size, rhs_size - 1);
			}
			break;
		default:
			break;
		}
	}
	vector<string> generateParenthesis(int n) {

		vector<string> v;
		if (n <= 0)
			return v;
		string s("(");
		gpth(v, s, n-1, n);
		return v;
	}
};
int main()
{
	Solution sl;
	vector<string> v = sl.generateParenthesis(3);
	for (auto & item : v)
	{
		cout << item << endl;
	}
	system("pause");
	return 0;
}