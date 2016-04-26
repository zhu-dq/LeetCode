/*
	��Ŀ��
			Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

			For example, given n = 3, a solution set is:

			"((()))", "(()())", "(())()", "()(())", "()()()"
	˼·��
			1. �ڹ���Ĺ����У�Ҫʱ�̱��֡����á� ����������>=����������
			2. ����ƥ��Ŀ�ʼ������"("��ʼ��������������="��"������˵��ǰ����Ѿ���ȫƥ���ˣ���ǰ���Ե���һ���µ�gpth
			3. ��ǰһ���ǡ�����ʱ��
					1�� �����С�����ʱ����ǰ�ɡ������ɡ�����
					2�� ��û�С�����ʱ��ʣ��ȫ��")"
			4. ��ǰһ���ǡ�����ʱ��
					1�� ������������==��������������ǰ�����ǡ�����
					2�� ������������Ϊ0��˵���������
					3�� �������������롰�����������ȣ�����ʣ�ࡿ�������������ڡ�����������ǰ�ɡ������ɡ�����
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