/*
	��Ŀ��32. Longest Valid Parentheses
	���ƥ���Ӵ�����ȫ������('(' ')')
	for example : "(()" : 2   ")()())" : 4
	��⣺
	��ÿ�������Ӵ�������һ���ں��ӣ�ֻҪ֪���ں��ӵ�ͷ��β����֪��ÿ���ں��Ӵ�С
	'('/')'[�ں���]'('/')'[�ں���]
	ÿ���ں��ӵ�β������i����ÿ���ں��ӵ�ͷ��������ջ�ϲ�������ջ����Ԫ�ء���Ϊ����ջ�Ļ����ں��ӻᱻ�ϲ�û�еġ�
*/
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<pair<char, int>> sta;
		sta.push(make_pair(')',-1));
		int i = 0;
		int max_cnt = 0;
		while (i<s.size())
		{
			switch (s[i])
			{
			case '(':
				sta.push(make_pair('(',i));
				break;
			case ')':
				if (sta.top().first == '(')
				{
					sta.pop();
					max_cnt = max(max_cnt,i-sta.top().second);//����  
				}
				else
				{
					sta.push(make_pair(')',i));
				}
				break;
			}
			i++;
		}
		return max_cnt;
	}
};

int main()
{
	Solution sl;
	int result1 = sl.longestValidParentheses("()(()");
	int result2 = sl.longestValidParentheses(")()())");
	int result3 = sl.longestValidParentheses("(()");
	int result4 = sl.longestValidParentheses("()(())");
	int result5 = sl.longestValidParentheses("(()()");
	cout << result1 << endl;
	cout << result2 << endl;
	cout << result3 << endl;
	cout << result4 << endl;
	cout << result5 << endl;
	system("pause");
	return 0;
}