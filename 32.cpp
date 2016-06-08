/*
	题目：32. Longest Valid Parentheses
	最长的匹配子串，串全是括号('(' ')')
	for example : "(()" : 2   ")()())" : 4
	题解：
	把每个完整子串看成是一个黑盒子，只要知道黑盒子的头和尾，即知道每个黑盒子大小
	'('/')'[黑盒子]'('/')'[黑盒子]
	每个黑盒子的尾部都是i。而每个黑盒子的头部是利用栈合并后还留在栈顶的元素。因为利用栈的话，黑盒子会被合并没有的。
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
					max_cnt = max(max_cnt,i-sta.top().second);//精髓  
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