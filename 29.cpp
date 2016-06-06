/*
	题目：29. Divide Two Integers
	Divide two integers without using multiplication, division and mod operator.
	If it is overflow, return MAX_INT.
	解析：
	核心是利用减法。
	优化每次把被除数加倍，从而加速
*/
#include <iostream>
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == 0)//分子为0
			return INT_MAX;
		if (dividend == INT_MIN && divisor == -1)//这种情况会出现溢出
			return INT_MAX;
		int sign = (dividend ^ divisor) >= 0 ? 1 : -1;
		long long a = dividend > 0 ? dividend : -(long long)dividend;
		long long b = divisor > 0 ? divisor : -(long long)divisor;
		long long result = 0;
		//原始方法
		/*
		while (a>=b)
		{
		a -= b;
		result += 1;
		}
		*/
		//优化方法
		while (a >= b)
		{
			long long temp = b;
			for (unsigned int i = 0; a >= temp; ++i, temp <<= 1)//每次分子是上次的二倍
			{
				a -= temp;
				result += 1 << i;
			}
		}
		return result * sign;
	}
};
int main()
{
	Solution sl;
	int result = sl.divide(21474836472,2);
	cout << result << endl;
	system("pause");
	return 0;
}