/*
	��Ŀ��29. Divide Two Integers
	Divide two integers without using multiplication, division and mod operator.
	If it is overflow, return MAX_INT.
	������
	���������ü�����
	�Ż�ÿ�ΰѱ������ӱ����Ӷ�����
*/
#include <iostream>
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == 0)//����Ϊ0
			return INT_MAX;
		if (dividend == INT_MIN && divisor == -1)//���������������
			return INT_MAX;
		int sign = (dividend ^ divisor) >= 0 ? 1 : -1;
		long long a = dividend > 0 ? dividend : -(long long)dividend;
		long long b = divisor > 0 ? divisor : -(long long)divisor;
		long long result = 0;
		//ԭʼ����
		/*
		while (a>=b)
		{
		a -= b;
		result += 1;
		}
		*/
		//�Ż�����
		while (a >= b)
		{
			long long temp = b;
			for (unsigned int i = 0; a >= temp; ++i, temp <<= 1)//ÿ�η������ϴεĶ���
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