
/*
	题目：

		自己实现一个 atoi()函数

	思路：

		1.考虑 int的范围
		2.考虑string是不是纯数字
		3.考虑stirng是不是为空
		4.考虑第一位 是不是符号位
		//---------
		5.忘了考虑“+43569870”'+'号了
		6.忘记考虑 开头的空格了 “  123”
		7. "  +  4335"
		8. "-+1" (错误的情况)
		9. "  -0012a42" (值 为 12)
		10. 一定要读清楚题意，下面的需求忘看了。。。
		11.判断越界好方法 ： if (new_result / 10 != old_result)

		//----------
		Requirements for atoi:

		The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

		The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

		If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

		If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

		
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {

		if (str.empty())
			return 0;

		bool  isNgetive = false;

		 long long i = 0;
		 int result=0;//就用int类型

		 while (str[i]==' ')
		 {
			 i++;
		 }

		if (str[i] == '-')
		{
			i++;
			isNgetive = true;
		}

		if (str[i] == '+')
		{
			if (isNgetive)
				return 0;
			i++;
		}


		for (; i < str.size(); i++)
		{
			long long s_copy = result;
			if (str[i] < 48 || str[i]>57)
				break;
			result = result * 10 + str[i]-48;

			/*
				这个思路好
			*/
			if (result / 10 != s_copy)
			{
				if (isNgetive)
					return INT_MIN;
				return INT_MAX;
			}
		}

		
		if (isNgetive)
			result = -result;
		/*
		if (result > INT_MAX)
			return INT_MAX;

		if (result < INT_MIN)
			return INT_MIN;
		*/
		return result;

	}
};

int main()
{
	Solution sl;
	string s("2147483648");
	int result = sl.myAtoi(s);
	cout << result << endl;
	system("pause");
	return 0;
}