/*
	题目:
		Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

		The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
	思路：
		用：栈
*/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack <char> s_stack;
		for (auto & c : s)
		{
			if (c == '(' || c == '{' || c == '[')
				s_stack.push(c);
			else
			{
				if (s_stack.empty())
					return false;
				switch (c)
				{
				case ')':
					if (s_stack.top() == '(')
						s_stack.pop();
					else
					{
						return false;
					}
					break;
				case '}':
					if (s_stack.top() == '{')
						s_stack.pop();
					else
					{
						return false;
					}
					break;
				case ']':
					if (s_stack.top() == '[')
						s_stack.pop();
					else
					{
						return false;
					}
					break;
				default:
					return false;
					break;
				}
			}
			/*
			else if (c == s_stack.top())
				s_stack.pop();
			else
				return false;
				*/
		}
		if (s_stack.empty())
			return true;
		else
			return false;
	}
};

int main()
{
	Solution sl;
	bool flag = sl.isValid("(])");
	cout << flag << endl;
	system("pause");
	return 0;
}