/*
	题目：

		Reverse digits of an integer.

		Example1: x = 123, return 321
		Example2: x = -123, return -321 

	思路：

		把int转换成字符串，反转字符串
		注意临界条件：INT_MIN  INT_MAX
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	int reverse(int x) {
	
		if (x == INT_MIN || x == INT_MAX)
			return 0;
		bool IsNegative = false;

		if (x < 0)
		{
			IsNegative = true;
			x = -x;
		}

		string s = to_string(x);
		std::reverse(s.begin(),s.end());
		
		long long int result;
		IsNegative ? result = -atoll(s.c_str()): result = atoll(s.c_str());
		if (result > INT_MAX || result < INT_MIN)
			result = 0;

		return result;
	}
};

int main(int argc,char * argv[])
{
	Solution sl;
	int test = 1534236469;
	long long int result = sl.reverse(test);
	cout << result << endl;
	system("pause");
	return 0;
}